#include "main.h"

/**
 * print_hex_lower - Prints an unsigned integer in lowercase hexadecimal format.
 * @n: The unsigned integer to be printed.
 *
 * Return: The number of characters printed.
 */

int print_hex_lower(unsigned int num, char flag)
{
	int count = 0;

	if (flag == '#' && num != 0)
		count += _puts("0x");

	count += print_number_base(num, 16);
	return (count);
}
