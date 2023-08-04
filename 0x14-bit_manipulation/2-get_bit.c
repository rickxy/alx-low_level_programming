#include "main.h"

/**
 * obtain_bit_value - Returns the value of a bit at a specified index.
 * @number: The number to check.
 * @bit_index: The index of the bit to retrieve.
 *
 * Return: If an error occurs - -1.
 *         Otherwise - the value of the bit at the given index.
 */
int obtain_bit_value(unsigned long int number, unsigned int bit_index)
{
    if (bit_index >= (sizeof(number) * 8))
        return (-1);

    return ((number >> bit_index) & 1);
}
