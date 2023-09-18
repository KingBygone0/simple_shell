#include "shell.h"

/**
 * copy_string - Copies a source string to a destination buffer.
 * @destination: The destination buffer.
 * @source: The source string.
 */
void copy_string(char *destination, const char *source)
{
        int source_len = string_len(source);
        int i = 0;

        while (i < source_len)
        {
                destination[i] = source[i];
                i++;
        }

        destination[i] = '\0';
}

/**
 * compare - Compare two strings using ASCII values.
 * @a1: The first string.
 * @a2: The second string.
 *
 * Return: Negative if a1 is lexicographically less than a2,
 * positive if a1 is lexicographically greater than a2,
 * and 0 if both strings are equal.
 */
int compare(const char *a1, const char *a2)
{
        while (*a1 && *a2)
        {
                if (*a1 != *a2)
                        return (*a1 - *a2);
                a1++;
                a2++;
        }

        return (*a1 - *a2);
}

/**
 * my_Atoi - Convert a string to an integer using ASCII values.
 * @string: The input string.
 *
 * Return: The integer value represented by the string.
 */
int my_Atoi(const char *string)
{
        int itr = 0, sign = 1, result = 0;

        /*Handle leading whitespace*/
        while (string[itr] == ' ')
                itr++;
        /*Handle optional sign*/
        if (string[itr] == '-' || string[itr] == '+')
        {
                if (string[itr] == '-')
                sign = -1;
                itr++;
        }

        /*Convert digits to integer*/
        while (string[itr] >= '0' && string[itr] <= '9')
        {
                result = result * 10 + (string[itr] - '0');
                itr++;
        }

        return (sign * result);
}

/**
 * my_strcspn - custom function
 * @str: string
 * @str2: other string
 *
 * Return: len
 */
size_t my_strcspn(const char *str, const char *str2)
{
        size_t len = 0;

        while (*str && strchr(str2, *str) == NULL)
        {
                str++;
                len++;
        }
                return (len);
}
