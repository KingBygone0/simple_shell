#include "shell.h"

/**
 * display_prompt - Display a shell prompt if the standard input is a terminal.
 */
void display_prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		char prompt[] = "($) ";

		write(STDOUT_FILENO, prompt, string_len(prompt));        }
}

/**
 * execute_exit - Exit the shell with a specified status code.
 * @args: An array of arguments. args[1] contains the status code (optional).
 */
void execute_exit(char **args)
{
	int status = 0;

	if (args[1] != NULL)
	{
		status = my_Atoi(args[1]);
		if (status == 0 && compare(args[1], "0") != 0)
		{
			perror("Invalid status");
			return;
		}
	}
	exit(status);
}

/**
 * execute_env - Display the environment variables to the standard output.
 */
void execute_env(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		write(STDOUT_FILENO, *env, string_len(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}
