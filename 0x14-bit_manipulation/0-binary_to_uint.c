#include "main.h"
#include <stddef.h>

/**
 * bin_str_to_uint - Converts a binary string to an unsigned int.
 * @binary_str: String containing binary digits (0 and 1)
 *
 * Return: The converted unsigned int value, or
 *         0 if there is one or more invalid characters in the string
 *         or if the input string is NULL
 */
unsigned int bin_str_to_uint(const char *binary_str)
{
    unsigned int result = 0;

    if (binary_str == NULL)
        return 0;

    while (*binary_str)
    {
        result <<= 1;
        if (*binary_str == '1')
            result += 1;
        else if (*binary_str != '0')
            return 0;
        binary_str++;
    }

    return result;
}
