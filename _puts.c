#include "main.h"

/**
 * _puts - Prints a string to stdout
 * @str: The string to print
 *
 * Return: Number of characters printed
 */
int _puts(char *str)
{
	int count = 0;

	if (!str)
		str = "(null)"; /* Handle NULL strings */

	while (*str)
	{
		_putchar(*str);
		str++;
		count++;
	}

	return (count);
}
