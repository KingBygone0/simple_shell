#include "shell.h"

/**
 * strip_comments - Remove all text after
 * the '#' symbol in the input line.
 * @input: The input line to process.
 */
void strip_comments(char *input)
{
	char *comment_start = strchr(input, '#');

	if (comment_start != NULL)
	{
		*comment_start = '\0';
	}
}

/**
 * main - Entry point for a simple shell program
 * @argc: The number of arguments passed to the program (unused)
 * @argv: An array of strings containing the program name and arguments
 *
 * Return: Always 0 to indicate successful execution.
 */
int main(int __attribute__((unused)) argc, char *argv[])
{
	char *input = NULL, *command, *args[MAX_INPUT_LENGTH];
	size_t input_length = 0;
	int num_args;
	char *program_name = argv[0];/*processed_input;*/

	if (program_name == NULL)
		program_name = argv[0];
	else
		program_name++;
	while (1)
	{
		display_prompt();
		if (!read_input_line(&input, &input_length, program_name))
		break;
	strip_comments(input);
	if (input[0] == '\0')
	{
		free(input);
		continue;
	}
	tokenize_input_line(input, &command, args, &num_args);
	if (command == NULL)
		continue;
	process_command(command, args, num_args, program_name);
	}
	free(input);
	return (0);
}
