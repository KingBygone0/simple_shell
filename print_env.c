#include "shell.h"
#include <stddef.h>

/**
 * _environment - Print the environment variables.
 */
void _environment(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		write(STDOUT_FILENO, *env, string_len(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}

