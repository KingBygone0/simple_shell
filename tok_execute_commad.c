#include "shell.h"

/**
 * execute_command - Execute a command with arguments in a new process.
 * @program_name: The name of the program calling execute_command.
 * @command: The command to execute.
 * @args: An array of arguments for the command.
 * Return: -1
 */

int execute_command(const char *program_name,
		const char *command, char *args[])
{
	int status;
	pid_t pid = fork();

	if (pid < 0)
	{
		perror(program_name);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(command, args, environ) == -1)
		{
			perror(program_name);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			return (WEXITSTATUS(status));
		}
	}
	return (-1);
}

/**
 * tokenize_input_line - Tokenize an input line into command and arguments.
 * @input: The input line to tokenize.
 * @command: A pointer to store the command.
 * @args: An array to store the arguments.
 * @num_args: A pointer to store the number of arguments.
 */
void tokenize_input_line(char *input, char **command,
		char *args[], int *num_args)
{
	char *token = strtok(input, " ");

	*num_args = 0;
	if (token == NULL)
	{
		*command = NULL;
		return;
	}
	*command = token;
	args[(*num_args)++] = token;
	while ((token = strtok(NULL, " ")) != NULL &&
			*num_args < MAX_INPUT_LENGTH - 1)
	{
		args[(*num_args)++] = token;
	}
	args[*num_args] = NULL;
}
