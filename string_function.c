#include "shell.h"

/**
 * string_len - Calculate the length of a string.
 * @w: The input string.
 *
 * Return: The length of the string.
 */
size_t string_len(const char *w)
{
        size_t l = 0;

        while (*w != '\0')
        {
                l++;
                w++;
        }

        return (l);
}

/**
 * sub_string - Find the first occurrence of a substring in a string.
 * @longstring: The string to search in.
 * @single: The substring to search for.
 *
 * Return: A pointer to the first occurrence
 * of the substring, or NULL if not found.
 */
char *sub_string(const char *longstring, const char *single)
{
        const char *l = longstring;
        const char *s = single;

        if (string_len(single) == 0)
        {
                return ((char *)longstring);
        }

        while (*longstring)
        {
                while (*s && (*l == *s))
                {
                        l++;
                        s++;
                }
                if (!*s)
                {
                        return ((char *)longstring);
                }
                        longstring++;
        }

        return (NULL);
}

/**
 * string_cmp - Compare two strings up to a specified number of characters.
 * @a1: The first string.
 * @a2: The second string.
 * @b: The maximum number of characters to compare.
 *
 * Return: The difference between the first differing characters or 0 if equal.
 */
int string_cmp(const char *a1, const char *a2, size_t b)
{
        size_t l1 = string_len(a1);
        size_t l2 = string_len(a2);
        size_t itr = 0, ml;
        unsigned char charA, charB;

        charA = (unsigned char)*(a1 + itr);
        charB = (unsigned char)*(a2 + itr);
        ml = (l1 < l2) ? l1 : l2;
        if (b > ml)
        {
                b = ml;
        }

        itr = 0;
        while (itr < b)
        {
                if (charA != charB)
                {
                        return (charA - charB);
                }
                itr++;
        }
                return (0);
}

/**
 * concat - Concatenate a source string to the end of a destination string.
 * @dt: The destination string.
 * @source: The source string to concatenate.
 *
 * Return: A pointer to the concatenated string.
 */
char *concat(char *dt, const char *source)
{
        char *dest = dt;

        while (*dest != '\0')
        {
                dest++;
        }

        while (*source != '\0')
        {
                *dest = *source;
                dest++;
                source++;
        }

        *dest = '\0';
        return (dt);
}

/**
 * duplicate - Create a duplicate of a string.
 * @string: The input string to duplicate.
 *
 * Return: A pointer to the duplicated string,
 * or NULL if memory allocation fails.
 */
char *duplicate(const char *string)
{
        size_t length = 0, i = 0;
        char *dup;

        if (!string)
        {
                return (NULL);
        }

        while (string[length])
        {
                length++;
        }
        dup = (char *)malloc((length + 1) * sizeof(char));
        if (!dup)
        {
                return (NULL);
        }
        while (string[i])
        {
                dup[i] = string[i];
                i++;
        }
                dup[i] = '\0';
                return (dup);
}
