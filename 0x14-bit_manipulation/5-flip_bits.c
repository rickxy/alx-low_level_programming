#include "main.h"

/**
 * flip_bits - Calculate the number of bits that must be toggled
 *             to transform one number into another.
 * @n: The first number.
 * @m: The second number.
 *
 * Return: The count of bits to be flipped.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
    unsigned long int xor_result = n ^ m;
    unsigned int flip_count = 0;

    while (xor_result)
    {
        flip_count += (xor_result & 1);
        xor_result >>= 1;
    }

    return (flip_count);
}
