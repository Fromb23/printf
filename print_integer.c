#include "main.h"
#include <unistd.h>

/**
 * print_integer - Prints an integer
 * @num: The integer to be printed
 *
 * Return: The number of characters printed
 */
int print_integer(int num, char flag, int width)
{
	int count = 0, divisor = 1, temp = num, num_len = 0, padding = 0;

	/* Determine the length of the number */
	if (num == 0)
		num_len = 1;
	else
	{
		while (temp != 0)
		{
			temp /= 10;
			num_len++;
		}
	}

	/* Include space for + or - sign */
	if (num >= 0 && (flag == '+' || flag == ' '))
		num_len++;

	/* Calculate padding needed */
	padding = (width > num_len) ? (width - num_len) : 0;

	/* Print padding spaces before the number */
	while (padding--)
		count += _putchar(' ');

	/* Handle flags for positive numbers */
	if (num >= 0)
	{
		if (flag == '+')
			count += _putchar('+');
		else if (flag == ' ')
			count += _putchar(' ');
	}
	else
	{
		count += _putchar('-');
		num = -num; /* Convert to positive */
	}

	/* Find the highest divisor */
	temp = num;
	while (temp / divisor >= 10)
		divisor *= 10;

	/* Print digits */
	while (divisor > 0)
	{
		count += _putchar((num / divisor) + '0');
		num %= divisor;
		divisor /= 10;
	}

	return (count);
}
