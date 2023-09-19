#include "shell.h"
/**
 * process_command - Process and execute commands.
 * @command: The command to process and execute.
 * @args: An array of command arguments.
 * @num_args: The number of arguments in the 'args' array.
 * @program_name: The name of the program.
 *
 * This function processes and executes commands,
 * including "setenv" and "unsetenv".
 * It provides appropriate error messages for incorrect usage.
 */
void process_command(const char *command, char **args,
		int num_args, const char *program_name)
{
	if (compare(command, "exit") == 0)
		execute_exit(args);
	else if (compare(command, "env") == 0)
		execute_env();
	else if (compare(command, "cd") == 0)
		execute_cd(args);
	else if (my_strchr(command, '/') != NULL)
		execute_command(program_name, command, args);
	else
		execute_command_in_path(program_name, command, args);
	if (compare(command, "setenv") == 0)
	{
		if (num_args != 3)
			perror("Usage: setenv VARIABLE value");
		else
		{
			execute_setenv(args[1], args[2]);
		}
	}
	else if (compare(command, "unsetenv") == 0)
	{
	if (num_args != 2)
		perror("Usage: unsetenv VARIABLE");
	else
		execute_unsetenv(args[1], program_name);
	}
}
