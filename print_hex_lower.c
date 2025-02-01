#include "main.h"

/**
 * print_hex_lower - Prints an unsigned integer in lowercase hexadecimal format.
 * @n: The unsigned integer to be printed.
 *
 * Return: The number of characters printed.
 */
int print_hex_lower(unsigned int n)
{
    int count = 0;
    if (n >= 16)
        count += print_hex_lower(n / 16);
    count += _putchar((n % 16) + (n % 16 < 10 ? '0' : 'a' - 10));
    return (count);
}
