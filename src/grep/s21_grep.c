#include "s21_grep.h"

int main(int argc, char *argv[]) {
  int error = FALSE;
  error = check_flags(argc, argv);
  return error;
}

int check_flags(int argc, char *argv[]) {
  int error = FALSE;
  OPTIONS;
  int res = -1;
  res = getopt(argc, argv, short_opt);
  if (res != '?') {
    int pos_file;
    if (res == 'f') {
      pos_file = optind;
    } else {
      pos_file = optind + 1;
    }
    open_files(argc, argv, &pos_file, &res);
  } else {
    error = TRUE;
    fprintf(stderr, "s21_grep: invalid option\n");
    fprintf(stderr, "Usage: s21_grep [-eivclnhsfo]... PATTERNS [FILE]...\n");
  }
  return error;
}

void open_files(int argc, char *argv[], int *pos_file, int *option) {
  while (argv[(*pos_file)] != NULL) {
    FILE *file;
    file = fopen(argv[(*pos_file)], "r");
    if (!file) {
      if (*option != 's') {
        fprintf(stderr, "s21_grep: %s: No such file or directory\n",
                argv[(*pos_file)]);
      }
    } else {
      int count_symb = _count_symb(*pos_file, argv);
      char *buff = (char *)calloc(1000, sizeof(char));
      if (*option == 'f') {
        if (buff != NULL) {
          pattern_flag_f(argv, buff);
        }
      }
      print_text_stdin_part1(argv, argc, file, argv[(*pos_file)], *option,
                             count_symb, buff);
      fclose(file);
      free(buff);
    }
    ++(*pos_file);
  }
}

int _count_symb(int pos_file, char *argv[]) {
  int count_symb = 1;
  FILE *file;
  file = fopen(argv[(pos_file)], "r");
  while (!(feof(file))) {
    count_symb++;
    fgetc(file);
  }
  fclose(file);
  return count_symb;
}

void print_text_stdin_part1(char *argv[], int argc, FILE *file, char *name_file,
                            const int option, int count_symb, char *buff) {
  regex_t template;
  long long int line_count = 0, c_line_count = 0;
  char *buffer_file = (char *)calloc(count_symb + 2, sizeof(char));
  if (buffer_file != NULL) {
    if (option == 'f') {
      regcomp(&template, buff, REG_EXTENDED);
    } else {
      regcomp(&template, argv[optind], REG_EXTENDED);
    }
    while (fgets(buffer_file, count_symb, file) != NULL) {
      size_t sizes = strlen(buffer_file);
      if (option == 'o') {
        regmatch_t flag_o;
        char *tmp = buffer_file;
#if __APPLE__
        int many_file = 0;
#endif
        while (regexec(&template, tmp, 1, &flag_o, 0) == 0) {
#if __linux__
          if (argc - optind >= 3) {
            printf("%s:", name_file);
          }
#elif __APPLE__
          if (argc - optind >= 3) {
            if (many_file == 0) {
              many_file = 1;
              printf("%s:", name_file);
            }
          }
#endif
          printf("%.*s\n", (int)(flag_o.rm_eo - flag_o.rm_so),
                 tmp + flag_o.rm_so);
          tmp = tmp + flag_o.rm_eo;
        }
      } else if (option == 'i') {
        regfree(&template);
        regcomp(&template, argv[optind], REG_ICASE | REG_EXTENDED);
        if (regexec(&template, buffer_file, 0, NULL, 0) == 0) {
          if (argc - optind >= 3) {
            printf("%s:", name_file);
          }
          printf("%s", buffer_file);
          if (buffer_file[sizes - 1] != '\n') {
            printf("\n");
          }
        }
      } else if (option == 'e' || option == 'n' || option == 'c' ||
                 option == -1 || option == 'h' || option == 's' ||
                 option == 'f') {
        line_count++;
        if (regexec(&template, buffer_file, 0, NULL, 0) == 0) {
          if (buffer_file[0] != '\n') {
            c_line_count++;
          }
          if (argc - optind >= 3 && option != 'c' && option != 'h')
            printf("%s:", name_file);
          if (option == 'f' && (argc - optind) >= 2) {
            printf("%s:", name_file);
          }
          if (option == 'n') {
            printf("%lld:", line_count);
          }
          if (option != 'c') {
            if (option == 'h' && buffer_file[0] != '\n') {
              printf("%s", buffer_file);
            } else if (option != 'h') {
              printf("%s", buffer_file);
            }
            if (buffer_file[sizes - 1] != '\n') {
              printf("\n");
            }
          }
        }
      } else if (option == 'v') {
        if (regexec(&template, buffer_file, 0, NULL, 0) != 0) {
          if (argc - optind >= 3) printf("%s:", name_file);
          printf("%s", buffer_file);
          if (buffer_file[sizes - 1] != '\n') {
            printf("\n");
          }
        }
      } else if (option == 'l') {
        if (regexec(&template, buffer_file, 0, NULL, 0) == 0) {
          printf("%s\n", name_file);
          break;
        }
      }
      buffer_file[0] = '\0';
    }
    if (option == 'c') {
      if (argc - optind >= 3) {
        printf("%s:", name_file);
      }
      printf("%lld\n", c_line_count);
    }
    free(buffer_file);
  }
  regfree(&template);
}

void pattern_flag_f(char *argv[], char *buf_pattern_2) {
  FILE *file_reg;
  file_reg = fopen(argv[optind - 1], "r");
  if (!file_reg) {
    fprintf(stderr, "s21_grep: %s: No such file or directory\n",
            argv[optind - 1]);
  } else {
    char c;
    int i = 0;
    char buf_pattern[1000] = "\0";
    fscanf(file_reg, "%c", &c);
    while (!(feof(file_reg))) {
      buf_pattern[i] = c;
      buf_pattern[i + 1] = '\0';
      fscanf(file_reg, "%c", &c);
      i++;
    }
    int pos_buf = 0;
    int pos_buf_2 = 0;
    int check = 0;
    while (i != 0) {
      if (buf_pattern[pos_buf] == '\n' && check == 0) {
        check = 1;
      }
      if (buf_pattern[pos_buf] != '\n') {
        buf_pattern_2[pos_buf_2] = buf_pattern[pos_buf];
        pos_buf_2++;
      }
      if (buf_pattern[pos_buf] == '\n' && buf_pattern[pos_buf + 1] != '\n' &&
          buf_pattern[pos_buf + 1] != '\0') {
        buf_pattern_2[pos_buf_2] = '|';
        pos_buf_2++;
      }
      pos_buf++;
      i--;
    }
    if (check == 1) {
      buf_pattern_2[pos_buf_2] = '|';
      buf_pattern_2[pos_buf_2 + 1] = '$';
      buf_pattern_2[pos_buf_2 + 2] = '\0';
    }
    if (buf_pattern_2[0] == '|') {
      buf_pattern_2[0] = buf_pattern_2[pos_buf_2 + 1];
    }
    fclose(file_reg);
  }
}
