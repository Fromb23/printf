#include "main.h"

/**
 * print_hex_upper - Prints an unsigned integer in uppercase hexadecimal format.
 * @n: The unsigned integer to be printed.
 *
 * Return: The number of characters printed.
 */
int print_hex_upper(unsigned int n)
{
    int count = 0;
    if (n >= 16)
        count += print_hex_upper(n / 16);
    count += _putchar((n % 16) + (n % 16 < 10 ? '0' : 'A' - 10));
    return (count);
}
