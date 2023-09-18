#include "shell.h"

/**
 * int_to_string - Converts an integer to a string.
 * @num: The integer to convert.
 *
 * Return: A string representation of the integer, or NULL on error.
 */
char *int_to_string(int num)
{
	int temp = num;
	int num_digits = 1;
	int i;
	char *buffer;

	while (temp / 10 != 0)
	{
		num_digits++;
		temp /= 10;
	}
	buffer = (char *)malloc(num_digits + 1);
	if (buffer == NULL)
	{
		return (NULL);
	}
	temp = num;
	buffer[num_digits] = '\0';
	for (i = num_digits - 1; i >= 0; i--)
	{
		buffer[i] = '0' + (temp % 10);
		temp /= 10;
	}
	return (buffer);
}

/**
 * handle_variables - Handle variable replacement for $? and $$.
 * @input: The input line to process.
 * @program_name: The name of the program.
 * @pid: The process ID of the shell.
 *
 * Return: A new string with variables replaced, or NULL on error.
 */

char *handle_variables(const char *input, const char *program_name, pid_t pid)
{
	const char *search, *replace_status = "0";
	char *temp;
	size_t input_len = strlen(input);
	char *result, *pos;
	char *replace_pid = int_to_string((int)pid);

	search = "$?";
	if (replace_pid == NULL)
	{
	return (NULL);
	}
	result = (char *)malloc(input_len + 1);
	if (result == NULL)
	{
		perror(program_name);
		free(replace_pid);
		return (NULL);
	}
	copy_string(result, input);
	pos = my_strstr(result, search);
	while (pos != NULL)
	{
		temp = (char *)malloc(input_len + 1);
		if (temp == NULL)
		{
			perror(program_name);
			free(result);
			free(replace_pid);
			return (NULL);
		}
		my_strncpy(temp, result, pos - result);
		concat(temp, replace_status);
		concat(temp, pos + string_len(search));
		copy_string(result, temp);
		free(temp);
		pos = my_strstr(result, search);
	}
	search = "$$";
	pos = my_strstr(result, search);
	while (pos != NULL)
	{
		temp = (char *)malloc(input_len + 1);
		if (temp == NULL)
		{
			perror(program_name);
			free(result);
			free(replace_pid);
			return (NULL);
		}
		my_strncpy(temp, result, pos - result);
		concat(temp, replace_pid);
		concat(temp, pos + string_len(search));
		copy_string(result, temp);
		free(temp);
		pos = my_strstr(result, search);
	}
	free(replace_pid);
	return (result);
}
