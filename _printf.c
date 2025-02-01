#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _putchar - Writes a character to stdout
 * @ch: The character to be printed
 *
 * Return: 1 on success, -1 on error
 */
int _putchar(char ch)
{
	return (write(1, &ch, 1));
}

/**
 * _printf - Custom printf function that handles %s, %c, %, %d, and %i
 * @format: The format string containing the characters and specifiers
 *
 * Return: The total number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	const char *ptr;
	va_list args;

	va_start(args, format);

	for (ptr = format; *ptr != '\0'; ptr++)
	{
		if (*ptr == '%')
		{
			specifier(args, &count, ptr);
		}
		else
		{
			_putchar(*ptr);
			count++;
		}
	}

	va_end(args);
	return (count);
}
