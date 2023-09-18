#include "shell.h"
struct EnvVar env_vars[MAX_ENV_VARS];

/**
 * my_setenv - Set or update an environment variable.
 * @name: The name of the environment variable.
 * @value: The value to set for the environment variable.
 * @overwrite: If 1, overwrite the existing
 * value if the variable already exists.
 *
 * Return: 0 on success, -1 on failure.
 */
int my_setenv(const char *name, const char *value, int overwrite)
{
	int i;
	int num_env_vars = 0;

	for (i = 0; i < num_env_vars; i++)
	{
		if (compare(name, env_vars[i].name) == 0)
		{
			if (overwrite)
			{
				free(env_vars[i].value);
				env_vars[i].value = duplicate(value);
				return (0);
			}
			else
			{
			return (0);
			}
		}
	}
	if (num_env_vars >= MAX_ENV_VARS)
	{
		return (-1);
	}
	env_vars[num_env_vars].name = duplicate(name);
	env_vars[num_env_vars].value = duplicate(value);
	num_env_vars++;
	return (0);
}
/**
 * my_unsetenv - Unset an environment variable.
 * @name: The name of the environment variable to unset.
 *
 * Return: 0 if the variable was successfully unset,
 * -1 if the variable was not found.
 */
int my_unsetenv(const char *name)
{
	int found = 0;
	int i, j;
	int num_env_vars = 0;

	for (i = 0; i < num_env_vars; i++)
	{
		if (compare(name, env_vars[i].name) == 0)
		{
			found = 1;
			free(env_vars[i].name);
			free(env_vars[i].value);
			for (j = i; j < num_env_vars - 1; j++)
			{
				env_vars[j] = env_vars[j + 1];
			}
			num_env_vars--;
			break;
		}
	}
	return (found ? 0 : -1);
}
