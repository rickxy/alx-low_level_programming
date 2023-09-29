#include "main.h"

/**
 * print_binary - Display the binary form of a given number.
 * @n: The input number to be shown in binary.
 */
void print_binary(unsigned long int n)
{
    if (n > 1)
        print_binary(n >> 1);

    _putchar((n & 1) + '0');
}
