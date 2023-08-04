#include "main.h"

/**
 * count_flipped_bits - Returns the number of bits needed to be flipped to transform
 *                      one number to another.
 * @num1: The first number.
 * @num2: The second number.
 *
 * Return: The count of bits to be flipped.
 */
unsigned int count_flipped_bits(unsigned long int num1, unsigned long int num2)
{
    unsigned long int xor_result = num1 ^ num2;
    unsigned int flipped_bits_count = 0;

    while (xor_result)
    {
        flipped_bits_count += (xor_result & 1);
        xor_result >>= 1;
    }

    return flipped_bits_count;
}
