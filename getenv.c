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

	while (command[command_length] != '\0')
	{
		command_length++;
	}
	while (*environment != NULL)
	{
		while (command[i] != '\0' && command[i] == (*environment)[i])
		{
			i++;
		}
		if (command[i] == '\0' && (*environment)[i] == '=')
		{
			return (*environment + i + 1);
		}
		environment++;
	}
	return (NULL);
}
