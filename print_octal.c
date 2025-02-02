#include "main.h"

/**
 * print_octal - Prints an unsigned integer in octal format.
 * @n: The unsigned integer to be printed.
 *
 * Return: The number of characters printed.
 */

int print_octal(unsigned int num, char flag)
{
        int count = 0;

        if (flag == '#' && num != 0)
                count += _putchar('0');

        count += print_number_base(num, 8);
        return (count);
}

int get_octal_length(unsigned int num, char flag)
{
	int num_len = (num == 0) ? 1 : 0;
	unsigned int temp = num;

	while (temp != 0)
	{
		temp /= 8;
		num_len++;
	}

	/* Account for '0' prefix */
	if (flag == '#' && num != 0)
		num_len += 1;

	return (num_len);
}
