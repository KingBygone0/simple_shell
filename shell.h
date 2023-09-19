#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <errno.h>
#include <stddef.h>
#include <stddef.h>
#include <string.h>


#define MAX_LEN 100
#define M_ARG 30
extern char **environ;
void execute_commands_from_file(const char *filename);
/* printing commands*/
void my_putchar(char c);
int my_puts(const char *string);
void _tokenize(char *input, char *tokens[], int *count);
void execute_command(char *command, char *arguments[]);
char *is_executable(char *command);
char *concat_strings(const char *a1, const char *a2);
char *my_path(const char *command);
void _environment(void);
size_t my_strcspn(const char *str, const char *str2);
void copy_string(char *destination, const char *source);
char *duplicate(const char *string);
char *concat(char *dt, const char *source);
int compare(const char *a1, const char *a2);
int string_cmp(const char *a1, const char *a2, size_t b);
void copy_string(char *destination, const char *source);
char *sub_string(const char *longstring, const char *single);
size_t string_len(const char *w);
char *my_strchr(const char *str, int character);
size_t my_strspn(const char *str, const char *accept);
char *my_strndup(const char *str, size_t n);
void split_commands(char *input, char *commands[], int *num_commands);
void execute_exit(char *args[]);
void execute_commands(const char *input);
void execute_logical_operators(const char *input);
int my_Atoi(const char *string);
#endif

