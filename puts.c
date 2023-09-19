#include "shell.h"

/**
 * my_putchar - Writes a character to standard output
 * @c: The character to be written
 */
void my_putchar(char c)
{
	write(1, &c, 1);
}

/**
 * my_puts - Writes a string to standard output
 * @s: The string to be written
 *
 * Return: The number of characters written, or EOF on error
 */
int my_puts(const char *s)
{

	int w = 0;

	if (!s)
	{
		return (EOF);
	}

	while (*s != '\0')
	{
		my_putchar(*s);
		w++;
		s++;
	}
	return (w);
}

