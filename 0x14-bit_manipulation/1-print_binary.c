#include "main.h"

/**
 * print_binary_representation - Prints the binary representation of a number.
 * @num: The number to be printed in binary.
 */
void print_binary_representation(unsigned long int num)
{
    if (num > 1)
        print_binary_representation(num >> 1);

    _putchar((num & 1) + '0');
}
