#include "shell.h"

/**
 * execute_command_in_path - Execute a command found
 * in the PATH environment variable.
 * @program_name: The name of the program calling execute_command_in_path.
 * @command: The command to search for and execute.
 * @args: An array of arguments for the command.
 */
void execute_command_in_path(const char *program_name,
		const char *command, char *args[])
{
	char *command_path = NULL, *path_copy, *path_token, *path = my_path("PATH");
	int command_not_found = 1;
	size_t path_len, command_len;

	if (path == NULL)
	{
		return;
	}
	path_copy = duplicate(path);
	if (path_copy == NULL)
	{
		return;
	}
	path_token = strtok(path_copy, ":");
	while (path_token != NULL)
	{
		path_len = string_len(path_token);
		command_len = string_len(command);
		command_path = (char *)malloc(path_len + command_len + 2);
		if (command_path == NULL)
		{
			perror(program_name);
			free(path_copy);
			return;
		}
		copy_string(command_path, path_token);
		concat(command_path, "/");
		concat(command_path, command);
		if (access(command_path, X_OK) == 0)
		{
			execute_command(program_name, command_path, args);
			command_not_found = 0;
			free(command_path);
			break;
		}
		free(command_path);
		path_token = strtok(NULL, ":");
	}
	free(path_copy);
	command_not_found ? perror(program_name) : (void)0;
}
