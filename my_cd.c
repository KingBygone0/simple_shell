#include "shell.h"

/**
 * read_input_line - Read a line of input from stdin.
 * @input: A pointer to store the input line.
 * @input_length: A pointer to store the length of the input line.
 * @program_name: The name of the program calling read_input_line.
 *
 * Return: 1 if input was successfully read,
 * 0 if it's the end of input, or exit(EXIT_FAILURE) on error.
 */
int read_input_line(char **input, size_t *input_length,
                        const char *program_name)
{
        if (getline(input, input_length, stdin) == -1)
        {
                if (feof(stdin))
        {
                if (isatty(STDIN_FILENO))
                {
                        write(STDOUT_FILENO, "\n", 1);
                }
                return (0);
                }
                else
                {
                        perror(program_name);
                        exit(EXIT_FAILURE);
                }
        }
        (*input)[string_len(*input) - 1] = '\0';
        return (1);
}

/**
 * execute_cd - Change the current working directory.
 * @args: An array of arguments. args[1]
 * contains the target directory (optional).
 */
void execute_cd(char *args[])
{
        const char *home = my_path("HOME"), *target_directory = args[1];
        char *current_directory;
        const char *error_message = "cd: HOME not set\n";

        if (target_directory == NULL)
        {
                target_directory = home;
        }
        else if (compare(target_directory, "-") == 0)
        {
                target_directory = getenv("OLDPWD");
        }
        if (target_directory == NULL)
        {
                write(STDERR_FILENO, error_message, string_len(error_message));
                return;
        }
                current_directory = getcwd(NULL, 0);
        if (current_directory == NULL)
        {
                perror("cd");
                return;
        }
        if (chdir(target_directory) == 0)
        {
                my_setenv("OLDPWD", current_directory, 1);
                my_setenv("PWD", getcwd(NULL, 0), 1);
        }
        else
        {
        perror("cd");
        }
        free(current_directory);
}
