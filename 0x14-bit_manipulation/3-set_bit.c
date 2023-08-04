#include "main.h"

/**
 * set_bit_value - Sets the value of a bit at a specified index to 1.
 * @number_ptr: A pointer to the number to modify.
 * @bit_index: The index of the bit to set.
 *
 * Return: If an error occurs - -1.
 *         Otherwise - 1.
 */
int set_bit_value(unsigned long int *number_ptr, unsigned int bit_index)
{
    if (bit_index >= (sizeof(*number_ptr) * 8))
        return (-1);

    *number_ptr |= 1UL << bit_index;

    return (1);
}
