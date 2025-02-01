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
        char flag = 0;

        while (*(ptr + 1) == '+' || *(ptr + 1) == ' ' || *(ptr + 1) == '#')
        {
                if (*(ptr + 1) == '+')
                        flag = '+';
                else if (*(ptr + 1) == ' ')
                        flag = (flag != '+') ? ' ' : flag;
                else if (*(ptr + 1) == '#')
                        flag = '#';

                ptr++; /* Move to actual specifier */
        }

        switch (*(ptr + 1))
        {
                case 'd':
                case 'i':
                {
                        int num = va_arg(args, int);
                        *count += print_integer(num, flag);
                        break;
                }
                case 'o':
                {
                        *count += print_octal(va_arg(args, unsigned int), flag);
                        break;
                }
                case 'x':
                {
                        *count += print_hex_lower(va_arg(args, unsigned int), flag);
                        break;
                }
                case 'X':
                {
                        *count += print_hex_upper(va_arg(args, unsigned int), flag);
                        break;
                }
                case 'p':
                {
                        void *ptr_val = va_arg(args, void *);
                        *count += print_pointer(ptr_val, flag);
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
