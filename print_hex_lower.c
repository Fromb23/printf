#include "main.h"

/**
 * print_hex_lower - Prints an unsigned integer in lowercase hexadecimal format.
 * @n: The unsigned integer to be printed.
 *
 * Return: The number of characters printed.
 */
int print_hex_lower(unsigned int num, char flag, int width)
{
	int count = 0, num_len = get_hex_length(num, flag);
	int padding = (width > num_len) ? (width - num_len) : 0;

	/* Print padding spaces before the number */
	count += print_padding(padding);

	/* Print '0x' if flag '#' is used and num isn't zero */
	if (flag == '#' && num != 0)
		count += _puts("0x");

	/* Print the actual number */
	count += print_number_base(num, 16);

	return (count);
}

int get_hex_length(unsigned int num, char flag)
{
	int num_len = (num == 0) ? 1 : 0;
	unsigned int temp = num;

	while (temp != 0)
	{
		temp /= 16;
		num_len++;
	}

	/* Account for '0x' prefix */
	if (flag == '#' && num != 0)
		num_len += 2;

	return (num_len);
}

int print_padding(int padding)
{
	int count = 0;

	while (padding-- > 0)
		count += _putchar(' ');

	return (count);
}
