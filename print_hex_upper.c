#include "main.h"

/**
 * print_hex_upper - Prints an unsigned integer in uppercase hexadecimal format.
 * @n: The unsigned integer to be printed.
 *
 * Return: The number of characters printed.
 */

int print_hex_upper(unsigned int num, char flag)
{
	int count = 0;

	if (flag == '#' && num != 0)
		count += _puts("0X");

	count += print_number_base_upper(num, 16);
	return (count);
}
