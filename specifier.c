#include "main.h"
#include <stdarg.h>

/**
 * specifier_basic - Handles basic conversion specifiers
 * @args: The argument list containing the values to print
 * @count: Pointer to the count of characters printed
 * @ptr: The current format specifier character
 *
 * Return: None
 */
void specifier_basic(va_list args, int *count, const char *ptr)
{
	switch (*(ptr + 1))
	{
		case 's':
		{
			char *str = va_arg(args, char *);
			*count += print_string(str);
			break;
		}
		case 'c':
		{
			char ch = (char)va_arg(args, int);
			*count += print_char(ch);
			break;
		}
		case '%':
		{
			*count += print_percent();
			break;
		}
		case 'd':
		case 'i':
		{
			int num = va_arg(args, int);
			*count += print_integer(num);
			break;
		}
		default:
		{
			specifier_advanced(args, count, ptr);
			break;
		}
	}
}

/**
 * specifier_advanced - Handles advanced conversion specifiers
 * @args: The argument list containing the values to print
 * @count: Pointer to the count of characters printed
 * @ptr: The current format specifier character
 *
 * Return: None
 */

void specifier_advanced(va_list args, int *count, const char *ptr)
{
	switch (*(ptr + 1))
	{
		case 'u':
		{
			*count += print_unsigned(va_arg(args, unsigned int));
			break;
		}
		case 'o':
		{
			*count += print_octal(va_arg(args, unsigned int));
			break;
		}
		case 'x':
		{
			*count += print_hex_lower(va_arg(args, unsigned int));
			break;
		}
		case 'X':
		{
			*count += print_hex_upper(va_arg(args, unsigned int));
			break;
		}
		default:
		{
			break;
		}
	}
}

