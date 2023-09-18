#include "shell.h"

/**
 * my_strchr - Locate character in string
 * @str: The string to search
 * @c: The character to locate
 *
 * Return: If character is found, return a pointer to the first
 * occurrence
 */
char *my_strchr(const char *str, int c)
{
        while (*str != '\0')
        {
                if (*str == (char)c)
                {
                        return ((char *)str);
                }
                        str++;
        }
        return (NULL);
}

/**
 * my_strncpy - Custom implementation of strncpy
 * @dest: Destination buffer
 * @src: Source string
 * @n: Maximum number of characters to copy
 *
 * Return: Pointer to the destination buffer 'dest'.
 */
char *my_strncpy(char *dest, const char *src, size_t n)
{
        char *dest_start = dest;

        /* Copy at most 'n' characters from 'src' to 'dest' */
        while (*src != '\0' && n > 0)
        {
                *dest++ = *src++;
                n--;
        }
        /* Null-terminate the 'dest' string if necessary */
        while (n > 0)
        {
                *dest++ = '\0';
                n--;
        }
        return (dest_start);
}

/**
 * my_strstr - Locates a substring within a string.
 * @haystack: The main string to search in.
 * @needle: The substring to search for.
 *
 * Return: If the substring is found, a pointer to the first occurrence
 *         of the substring in the haystack. If not found, NULL.
 */
char *my_strstr(const char *haystack, const char *needle)
{
        if (!haystack || !needle)
                return (NULL);

        if (*needle == '\0')
                return ((char *)haystack);

        while (*haystack)
        {
                const char *h = haystack;
                const char *n = needle;

                while (*h && *n && *h == *n)
                {
                        h++;
                        n++;
                }

                if (*n == '\0')
                        return ((char *)haystack);

                haystack++;
        }

        return (NULL);
}
