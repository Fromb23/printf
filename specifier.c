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
	char flag = 0, length = 0;

	while (*(ptr + 1) == '+' || *(ptr + 1) == ' ' || *(ptr + 1) == '#')
	{
		if (*(ptr + 1) == '+')
			flag = '+';
		else if (*(ptr + 1) == ' ')
			flag = (flag != '+') ? ' ' : flag;
		else if (*(ptr + 1) == '#')
			flag = '#';
		ptr++;
	}

	if (*(ptr + 1) == 'h' || *(ptr + 1) == 'l')
	{
		length = *(ptr + 1);
		ptr++;
	}

	if (*(ptr + 1) == 'd' || *(ptr + 1) == 'i')
		*count += handle_signed_length_modifier(args, length, flag);
	else if (*(ptr + 1) == 'u' || *(ptr + 1) == 'o' ||
	         *(ptr + 1) == 'x' || *(ptr + 1) == 'X')
		*count += handle_unsigned_length_modifier(args, length, flag,
		                                          *(ptr + 1));
	else if (*(ptr + 1) == 'p')
		*count += print_pointer(va_arg(args, void *), flag);
	else
		specifier_advanced(args, count, ptr);
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
                case 's':
                {
                        char *str = va_arg(args, char *);
                        *count += print_string(str);
                        break;
                }
                case 'u':
                {
                        *count += print_unsigned(va_arg(args, unsigned int));
                        break;
                }
                case 'S':
                {
                        char *str = va_arg(args, char *);
                        *count += print_custom_string(str);
                        break;
                }
                default:
                {
                        break;
                }
        }
}

/**
 * handle_signed_length_modifier - Handles length modifiers for signed types
 * @args: Argument list
 * @length: 'h' for short, 'l' for long, 0 for default
 * @flag: Flag character for formatting
 *
 * Return: Number of characters printed
 */
int handle_signed_length_modifier(va_list args, char length, char flag)
{
	if (length == 'l')
		return (print_integer(va_arg(args, long), flag));
	if (length == 'h')
		return (print_integer((short)va_arg(args, int), flag));
	return (print_integer(va_arg(args, int), flag));
}

/**
 * handle_unsigned_length_modifier - Handles length modifiers for unsigned types
 * @args: Argument list
 * @length: 'h' for short, 'l' for long, 0 for default
 * @flag: Flag character for formatting
 * @specifier: Conversion specifier ('u', 'o', 'x', 'X')
 *
 * Return: Number of characters printed
 */
int handle_unsigned_length_modifier(va_list args, char length,
                                    char flag, char specifier)
{
	unsigned long num;

	if (length == 'l')
		num = va_arg(args, unsigned long);
	else if (length == 'h')
		num = (unsigned short)va_arg(args, unsigned int);
	else
		num = va_arg(args, unsigned int);

	if (specifier == 'u')
		return (print_unsigned(num));
	if (specifier == 'o')
		return (print_octal(num, flag));
	if (specifier == 'x')
		return (print_hex_lower(num, flag));
	return (print_hex_upper(num, flag));
}
