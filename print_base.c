#include "main.h"

/**
 * print_number_base - Prints an unsigned number in a given base (lowercase).
 * @num: The number to print.
 * @base: The base to use (e.g., 8 for octal, 16 for hex).
 * Return: The count of characters printed.
 */
int print_number_base(unsigned int num, int base)
{
	int count = 0;
	char digits[] = "0123456789abcdef";

	if (num >= (unsigned int)base)
		count += print_number_base(num / base, base);
	_putchar(digits[num % base]);
	return (count + 1);
}

/**
 * print_number_base_upper - Prints an unsigned number in a given base (uppercase).
 * @num: The number to print.
 * @base: The base to use (e.g., 8 for octal, 16 for hex).
 * Return: The count of characters printed.
 */
int print_number_base_upper(unsigned int num, int base)
{
	int count = 0;
	char digits[] = "0123456789ABCDEF";

	if (num >= (unsigned int)base)
		count += print_number_base_upper(num / base, base);
	_putchar(digits[num % base]);
	return (count + 1);
}
