#include "main.h"

/**
 * clear_bit - Clears the value of a bit at a given index.
 * @n: A pointer to the number to clear.
 * @index: The index to clear.
 *
 * Return: If an error occurred - -1.
 *		 Otherwise - 1.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= (sizeof(*n) * 8))
		return (-1);

	*n &= ~(1UL << index);

	return (1);
}
