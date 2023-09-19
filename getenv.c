#include "shell.h"
/**
 * my_path - Find the value of an environment variable.
 * @command: The environment variable to search for.
 *
 * Return: If found, returns a pointer to the value of the environment
 *         variable. If not found, returns NULL.
 */
char *my_path(const char *command)
{
	size_t command_length = 0;
	char **environment = environ;
	size_t i = 0;

	/* Calculate the length of the command */
	while (command[command_length] != '\0')
	{
		command_length++;
	}

	/* Iterate through each environment variable */
	while (*environment != NULL)
	{
		/* Compare the command with the current environment variable */
		while (command[i] != '\0' && command[i] == (*environment)[i])
		{
			i++;
		}
		/* Check if the command matches the environment variable format */
		if (command[i] == '\0' && (*environment)[i] == '=')
		{
			return (*environment + i + 1);
		}
		/* Move to the next environment variable */
		environment++;
	}

	/* Return NULL if environment variable is not found */
	return (NULL);
}

