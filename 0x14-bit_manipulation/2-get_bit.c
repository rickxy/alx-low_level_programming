#include "main.h"

/**
 * get_bit - Retrieve the bit value at a specified index.
 * @n: The number to be inspected.
 * @index: The index of the bit to check.
 *
 * Return: If an error occurs, return -1.
 *         Otherwise, return the value of the bit at the given index.
 */
int get_bit(unsigned long int n, unsigned int index)
{
    if (index >= (sizeof(n) * 8))
        return (-1);

    return ((n >> index) & 1);
}
