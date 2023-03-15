#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_

#include <errno.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

#if __APPLE__
#define FLAGS
const char* short_opt = "benstv";
const struct option long_options[] = {{NULL, 0, NULL, 0}};
#elif __linux__
#define FLAGS
const char* short_opt = "bnsveEtT";
const struct option long_options[] = {
    {"number-nonblank", no_argument, NULL, 'b'},
    {"number", no_argument, NULL, 'n'},
    {"squeeze-blank", no_argument, NULL, 's'},
    {NULL, 0, NULL, 0}};
#endif
#if __APPLE__
#define LINE int line = 1;
#elif __linux__
#define LINE static int line = 1;
#endif
struct cat_flag {
  int b;
  int e;
  int n;
  int s;
  int t;
  int v;
  int E;
  int T;
};
int check_flags(int argc, char** argv, struct cat_flag flags);
void open_files(char** argv, int* pos_file, struct cat_flag flags);
void print_text_stdin(struct cat_flag flags, FILE* file);
void print_flag_b(FILE* file);
void print_flag_n(FILE* file);
void print_flag_s(FILE* file);
void print_flag_v(FILE* file, int check);
void print_flag_e(FILE* file);
void print_flag_E(FILE* file);
void print_flag_tt(FILE* file);
void print_flag_T(FILE* file);
void print_default(FILE* fiel);

#endif  // SRC_CAT_S21_CAT_H_
