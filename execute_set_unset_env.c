#include "shell.h"

/**
 * execute_setenv - Set an environment variable.
 * @variable: The name of the variable to set.
 * @value: The value to assign to the variable.
 */
void execute_setenv(const char *variable, const char *value)
{
	if (my_setenv(variable, value, 1) != 0)
	{
		write(STDERR_FILENO, "Error: Unable to set environment variable\n", 41);
	}
}

/**
 * execute_unsetenv - Unset an environment variable.
 * @variable: The name of the variable to unset.
 * @program_name: The name of the program calling execute_unsetenv.
 */
void execute_unsetenv(const char *variable, const char *program_name)
{
	const char *error_message;

	if (my_unsetenv(variable) != 0)
	{
		error_message = "Unable to unset environment variable\n";
		write(STDERR_FILENO, program_name, strlen(program_name));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, error_message, strlen(error_message));
	}
}
