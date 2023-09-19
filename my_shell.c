#include "shell.h"

/**
 * concat_strings - Concatenate two strings with a slash in between.
 * @a1: First string.
 * @a2: Second string.
 * Return: Concatenated string.
 */
char *concat_strings(const char *a1, const char *a2)
{
	char *output = (char *)malloc(string_len(a1) + string_len(a2) + 2);

	if (output == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	copy_string(output, a1);
	concat(output, "/");
	concat(output, a2);
	return (output);
}

/**
 * is_executable - Check if a command is executable.
 * @command: Command to check.
 * Return: Full path of the executable if found, else NULL.
 */
char *is_executable(char *command)
{
	char *path = my_path("PATH");
	char *dir = strtok(path, ":");
	char *executable_path = NULL;

	if (access(command, X_OK) == 0)
	{
		return (duplicate(command));
	}
		while (dir != NULL)
	{
		executable_path = concat_strings(dir, command);

		if (access(executable_path, X_OK) == 0)
		{
			return (executable_path);
		}
		free(executable_path);
		dir = strtok(NULL, ":");
	}
	return (NULL);
}

/**
 * execute_command - Execute a command with given arguments.
 * @command: Command to execute.
 * @arguments: Arguments for the command.
 */
void execute_command(char *command, char *arguments[])
{
	char *executable_path = is_executable(command);

	if (executable_path == NULL)
	{
		write(STDERR_FILENO, command, string_len(command));
		write(STDERR_FILENO, ": command not found\n", 20);
		exit(EXIT_FAILURE);
	}
	execve(executable_path, arguments, environ);
	perror(executable_path);

	free(executable_path);
	exit(EXIT_FAILURE);
}

/**
 * _tokenize - Tokenize input string into arguments.
 * @input: Input string to tokenize.
 * @tokens: Array to store tokens.
 * @count: Pointer to store the token count.
 */
void _tokenize(char *input, char *tokens[], int *count)
{
	char *token;

	*count = 0;
	token = strtok(input, " ");
	while (token != NULL && *count < M_ARG - 1)
	{
		tokens[(*count)++] = duplicate(token);
		token = strtok(NULL, " ");
	}
	tokens[*count] = NULL;
}

/**
 * main - main entry
 *
 * Return: 0
 */
int main(void)
{
	char *command = NULL, *arguments[M_ARG];
	size_t command_size = 0;
	int arg_count, i, is_interactive = isatty(STDIN_FILENO);
	ssize_t read_size;
	pid_t pid;

	while (1)
	{
		if (is_interactive)
		{
			write(STDOUT_FILENO, "($) ", 4);
		}
		read_size = getline(&command, &command_size, stdin);
	if (read_size == -1)
	{
		if (feof(stdin))
		break;
	}
	command[my_strcspn(command, "\n")] = '\0';
	if (compare(command, "exit") == 0)
		break;
	else if (compare(command, "env") == 0)
		_environment();
	else
	{
		_tokenize(command, arguments, &arg_count);
		pid = fork();
		if (pid == -1)
		perror("fork");
		else if (pid == 0)
		execute_command(arguments[0], arguments);
		else
		wait(NULL);
		for (i = 0; i < arg_count; i++)
		free(arguments[i]);
	}
	}
	free(command);
	return (0);
}

