#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#define MAX_ENV_VARS 100
#define MAX_INPUT_LENGTH 1024
extern int num_env_vars;
extern char **environ;
/**
 * struct EnvVar - Structure to represent an environment variable.
 * @name: The name of the environment variable.
 * @value: The value associated with the environment variable.
 */
struct EnvVar
{
        char *name;
        char *value;
};

void strip_comments(char *input);
void execute_setenv(const char *variable,
                        const char *value);
void execute_unsetenv(const char *variable, const char *program_name);
int my_setenv(const char *name, const char *value, int overwrite);
int my_unsetenv(const char *name);
char *int_to_string(int num);
void display_prompt(void);
void execute_exit(const char *command, char **args);
void execute_env(void);
int execute_command(const char *program_name,
                const char *command, char *args[]);
void tokenize_input_line(char *input, char **command,
                        char *args[], int *num_args);
void execute_command_in_path(const char *program_name,
                const char *command, char *args[]);
int read_input_line(char **input, size_t *input_length,
                        const char *program_name);
void execute_cd(char *args[]);
void copy_string(char *destination, const char *source);
int compare(const char *a1, const char *a2);
int my_Atoi(const char *string);
size_t my_strcspn(const char *str, const char *str2);
size_t string_len(const char *w);
char *sub_string(const char *longstring, const char *single);
int string_cmp(const char *a1, const char *a2, size_t b);
char *concat(char *dt, const char *source);
char *duplicate(const char *string);
void execute_individual_command(char *program_name,
                        char *command, char *args[]);
char *handle_variables(const char *input,
                const char *program_name, pid_t pid);
char *my_path(const char *command);
void process_command(const char *command, char **args,
                int num_args, const char *program_name);
char *my_strchr(const char *str, int c);
char *my_strncpy(char *dest, const char *src, size_t n);
char *my_strstr(const char *haystack, const char *needle);
#endif
