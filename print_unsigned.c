#include "main.h"

/**
 * print_unsigned - Prints an unsigned integer.
 * @n: The unsigned integer to be printed.
 *
 * Return: The number of characters printed.
 */
int print_unsigned(unsigned int n, int width)
{
	int count = 0, num_len = 0, padding = 0;
	unsigned int temp = n;

	/* Determine the number of digits */
	if (n == 0)
		num_len = 1;
	else
	{
		while (temp != 0)
		{
			temp /= 10;
			num_len++;
		}
	}

	/* Calculate padding needed */
	padding = (width > num_len) ? (width - num_len) : 0;

	/* Print padding spaces before the number */
	while (padding-- > 0)
		count += _putchar(' ');

	/* Print the actual unsigned number */
	count += print_number_base(n, 10);

	return (count);
}
