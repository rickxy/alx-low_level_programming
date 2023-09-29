#include "main.h"
#include <stddef.h>
/**
 * binary_to_uint - Converts a binary string to an unsigned integer.
 * @b: A string consisting of '0' and '1' characters representing a binary number
 *
 * Return: The converted unsigned integer value, or
 *         0 if the input string @b contains any non-binary characters ('0' or '1')
 *         or if @b is NULL
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int num = 0;
	if (b == NULL)
		return (0);
	while (*b)
	{
		num <<= 1;
		if (*b == '1')
			num += 1;
		else if (*b != '0')
			return (0);
		b++;
	}
	return (num);
}
