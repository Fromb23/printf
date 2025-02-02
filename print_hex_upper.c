#include "main.h"

/**
 * print_hex_upper - Prints an unsigned integer in uppercase hexadecimal format.
 * @n: The unsigned integer to be printed.
 *
 * Return: The number of characters printed.
 */

int print_hex_upper(unsigned int num, char flag, int width)
{
	int count = 0, num_len = get_hex_length(num, flag);
	int padding = (width > num_len) ? (width - num_len) : 0;

	/* Print padding spaces before the number */
	count += print_padding(padding);

	/* Print '0X' if flag '#' is used and num isn't zero */
	if (flag == '#' && num != 0)
		count += _puts("0X");

	/* Print the actual number */
	count += print_number_base_upper(num, 16);

	return (count);
}
