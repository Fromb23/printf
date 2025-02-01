#include "main.h"
#include <unistd.h>

/**
 * print_integer - Prints an integer
 * @num: The integer to be printed
 *
 * Return: The number of characters printed
 */
int print_integer(int num, char flag)
{
	int count = 0, divisor = 1, temp = num;

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
		_putchar('-');
		num = -num; /* Convert to positive for digit extraction */
		count++;
	}

	/* Find the highest divisor */
	while (temp / divisor >= 10)
		divisor *= 10;

	/* Print digits */
	while (divisor > 0)
	{
		_putchar((num / divisor) + '0');
		num %= divisor;
		divisor /= 10;
		count++;
	}

	return (count);
}
