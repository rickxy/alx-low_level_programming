#include "main.h"

/**
 * binary_printer - Outputs the binary form of a given number.
 * @num: The numerical value to be displayed in binary.
 */
void binary_printer(unsigned long int num)
{
    if (num > 1)
        binary_printer(num >> 1);

    putchar((num & 1) + '0');
}
