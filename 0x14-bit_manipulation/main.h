#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>

int _putchar(char c);
unsigned int bin_str_to_uint(const char *binary_str);
void print_binary_representation(unsigned long int num);
int obtain_bit_value(unsigned long int number, unsigned int bit_index);
int set_bit_value(unsigned long int *number_ptr, unsigned int bit_index);
int clear_bit_at_index(unsigned long int *number_ptr, unsigned int bit_index);
unsigned int count_flipped_bits(unsigned long int num1, unsigned long int num2);
int check_endianness(void);

#endif /* MAIN_H */
