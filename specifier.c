#include "main.h"
#include <stdarg.h>

/**
 * specifier - Handles conversion specifiers
 * @args: The argument list containing the values to print
 * @count: Pointer to the count of characters printed
 * @ptr: The current format specifier character
 *
 * Return: None
 */
void specifier(va_list args, int *count, const char *ptr)
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
				/* Handle invalid specifier (optional) */
				break;
			}
	}
}
