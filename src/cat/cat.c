#include "cat.h"

int main(int argc, char* argv[]) {
  int error = FALSE;
  struct cat_flag flags = {FALSE, FALSE, FALSE, FALSE,
                           FALSE, FALSE, FALSE, FALSE};
  error = check_flags(argc, argv, flags);
  return error;
}

int check_flags(int argc, char** argv, struct cat_flag flags) {
  FLAGS;
  int error = FALSE;
  int res = -1;
  int opt_index = -1;
  do {
    res = getopt_long(argc, argv, short_opt, long_options, &opt_index);
    switch (res) {
      case 'b':
        flags.b = TRUE;
        break;
      case 'n':
        flags.n = TRUE;
        break;
      case 's':
        flags.s = TRUE;
        break;
      case 'v':
        flags.v = TRUE;
        break;
      case 'e':
        flags.e = TRUE;
        break;
      case 'E':
        flags.E = TRUE;
        break;
      case 't':
        flags.t = TRUE;
        break;
      case 'T':
        flags.T = TRUE;
        break;
      case '?':
        fprintf(stderr, "usage: cat [options] [file ...]\n");
        error = TRUE;
        break;
    }
  } while (res != -1 && error != TRUE);
  if (error == FALSE) {
    int pos_file = optind;
    open_files(argv, &pos_file, flags);
  }
  return error;
}
void open_files(char** argv, int* pos_file, struct cat_flag flags) {
  while (argv[(*pos_file)] != NULL) {
    FILE* file;
    file = fopen(argv[(*pos_file)], "r");
    if (!file) {
      fprintf(stderr, "cat: %s: No such file or directory\n",
              argv[(*pos_file)]);
    } else {
      print_text_stdin(flags, file);
      fclose(file);
    }
    (*pos_file)++;
  }
}

void print_text_stdin(struct cat_flag flags, FILE* file) {
  if (flags.b) {
    print_flag_b(file);
  } else if (flags.n) {
    print_flag_n(file);
  } else if (flags.s) {
    print_flag_s(file);
  } else if (flags.v) {
    print_flag_v(file, 0);
  } else if (flags.e) {
    print_flag_e(file);
  } else if (flags.E) {
    print_flag_E(file);
  } else if (flags.t) {
    print_flag_tt(file);
  } else if (flags.T) {
    print_flag_T(file);
  } else {
    print_default(file);
  }
}
void print_flag_b(FILE* file) {
  unsigned char c;
  LINE;
  int costyl = 0;
  c = fgetc(file);
  while (!(feof(file))) {
    if (c == '\n') {
      costyl = 1;
    } else if (costyl != 2) {
      costyl = 0;
    }
    if (costyl == 0) {
      printf("%6d\t", line);
      line++;
      costyl = 2;
    }
    printf("%c", c);
    c = fgetc(file);
  }
}
void print_flag_n(FILE* file) {
  unsigned char c;
  LINE;
  int costyl = 2;
  c = fgetc(file);
  while (!(feof(file))) {
    if (line == 1 && costyl == 2) {
      printf("%6d\t", line);
      costyl = 1;
      line++;
    }
    if (costyl == 0) {
      printf("%6d\t", line);
      line++;
      costyl = 1;
    }
    if (c == '\n') {
      costyl = 0;
    }
    printf("%c", c);
    c = fgetc(file);
  }
}
void print_flag_s(FILE* file) {
  unsigned char c;
  int costyl = 0;
  c = fgetc(file);
  while (!(feof(file))) {
    if (c == '\n') {
      printf("%c", c);
      c = fgetc(file);
      if (costyl == 0) {
        while (c == '\n' && !(feof(file))) {
          c = fgetc(file);
        }
      }
      if (c == '\n' && costyl != 0) {
        printf("%c", c);
        c = fgetc(file);
        while (c == '\n' && !(feof(file))) {
          c = fgetc(file);
        }
      }
    }
    if (!(feof(file))) {
      costyl = 1;
      printf("%c", c);
      c = fgetc(file);
    }
  }
}
void print_flag_v(FILE* file, int check) {
  unsigned char c;
  int costyl;
  c = fgetc(file);
  while (!(feof(file))) {
    costyl = 0;
    if (c <= 31 && c != 10 && c != 9) {
      printf("^%c", c + 64);
      costyl = 1;
    } else if (c >= 128 && c <= 159) {
      printf("M-^%c", c - 64);
      costyl = 1;
    } else if (c == 127) {
      printf("^?");
      costyl = 1;
    } else if (c == 10 && check == 101) {
      printf("$\n");
      costyl = 1;
    } else if (c == 9 && check == 116) {
      printf("^I");
      costyl = 1;
    }
#if __linux__
    if (c >= 160 && c <= 254) {
      printf("M-%c", c - 128);
      costyl = 1;
    } else if (c == 255) {
      printf("M-^?");
      costyl = 1;
    }
#endif
    if (costyl == 0) {
      printf("%c", c);
    }
    c = fgetc(file);
  }
}

void print_flag_e(FILE* file) {
  int check = 101;
  print_flag_v(file, check);
}
void print_flag_E(FILE* file) {
  unsigned char c;
  c = fgetc(file);
  while (!(feof(file))) {
    if (c == '\n') {
      printf("$\n");
    } else {
      printf("%c", c);
    }
    c = fgetc(file);
  }
}
void print_flag_tt(FILE* file) {
  int check = 116;
  print_flag_v(file, check);
}
void print_flag_T(FILE* file) {
  unsigned char c;
  c = fgetc(file);
  while (!(feof(file))) {
    if (c == '\t') {
      printf("^I");
    } else {
      printf("%c", c);
    }
    c = fgetc(file);
  }
}
void print_default(FILE* file) {
  unsigned char c;
  c = fgetc(file);
  while (!(feof(file))) {
    printf("%c", c);
    c = fgetc(file);
  }
}
