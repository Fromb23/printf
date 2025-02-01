#include "main.h"
#include <unistd.h>

/**
 * print_integer - Prints an integer
 * @num: The integer to be printed
 *
 * Return: The number of characters printed
 */
int print_integer(int num)
{
	int count = 0;
	int divisor = 1;
	int temp = num;

	if (num < 0)
	{
		_putchar('-');
		num = -num;
		count++;
	}

	/* Find the highest divisor for the number */
	while (temp / divisor >= 10)
		divisor *= 10;

	/* Print the individual digits */
	while (divisor > 0)
	{
		_putchar((num / divisor) + '0');
		num %= divisor;
		divisor /= 10;
		count++;
	}

	return (count);
}
