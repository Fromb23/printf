#include "main.h"

/**
 * print_custom_string - Prints a string with non-printable characters formatted
 * @str: The string to be printed
 *
 * Return: Number of characters printed
 */
int print_custom_string(char *str)
{
	int count = 0;
	char hex[3];

	if (!str)
		str = "(null)";

	while (*str)
	{
		if (*str < 32 || *str >= 127)
		{
			count += _putchar('\\');
			count += _putchar('x');
			hex[0] = ((*str >> 4) & 0xF) + '0';
			hex[1] = (*str & 0xF) + '0';
			if (hex[0] > '9') /* Convert to uppercase hex */
				hex[0] += 7;
			if (hex[1] > '9')
				hex[1] += 7;
			count += _putchar(hex[0]);
			count += _putchar(hex[1]);
		}
		else
		{
			count += _putchar(*str);
		}
		str++;
	}
	return (count);
}
