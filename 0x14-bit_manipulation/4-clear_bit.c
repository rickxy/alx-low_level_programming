#include "main.h"

/**
 * clear_bit_at_index - Clears the value of a bit at a specified index.
 * @number_ptr: A pointer to the number to modify.
 * @bit_index: The index of the bit to clear.
 *
 * Return: If an error occurs - -1.
 *         Otherwise - 1.
 */
int clear_bit_at_index(unsigned long int *number_ptr, unsigned int bit_index)
{
    if (bit_index >= (sizeof(*number_ptr) * 8))
        return (-1);

    *number_ptr &= ~(1UL << bit_index);

    return (1);
}
