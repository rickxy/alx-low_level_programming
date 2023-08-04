#include "main.h"

/**
 * flip_bits - Returns the number of bits needed to be flipped to get
 *			 from one number to another.
 * @n: The first number.
 * @m: The second number.
 *
 * Return: The number of bits to be flipped.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor = n ^ m;
	unsigned int flip_count = 0;

	while (xor)
	{
		flip_count += (xor & 1);
		xor >>= 1;
	}

	return (flip_count);
}
