#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_

#include <errno.h>
#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define OPTIONS const char *short_opt = "eivclnhsf:o"
void open_files(int argc, char *argv[], int *pos_file, int *option);
int _count_symb(int pos_file, char *argv[]);
int check_flags(int argc, char *argv[]);
void print_text_stdin_part1(char *argv[], int argc, FILE *file, char *name_file,
                            const int option, int count_symb, char *buff);
void pattern_flag_f(char *argv[], char *buf_pattern_2);
#endif  // SRC_GREP_S21_GREP_H_
