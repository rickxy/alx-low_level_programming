#include "main.h"

/**
 * check_endianness - Checks the endianness of the current machine.
 *
 * Return: 0 if big-endian, 1 if little-endian.
 */
int check_endianness(void)
{
    unsigned int value = 1;
    char *byte_ptr = (char *)&value;

    if (*byte_ptr)
        return 1; // Little-endian
    else
        return 0; // Big-endian
}
