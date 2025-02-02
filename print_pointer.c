#include "main.h"
#include <stdint.h>

/**
 * print_pointer - Prints a memory address in hexadecimal format
 * @ptr: The pointer to be printed
 * @flag: The flag to modify the output (e.g., for '#' or other formatting)
 *
 * Return: Number of characters printed
 */
int print_pointer(void *ptr, char flag, int width)
{
	uintptr_t addr;
	int count = 0, num_len = 0, padding = 0;

	if (!ptr)
		return (_puts("(nil)")); /* Handle NULL pointer */

	addr = (uintptr_t)ptr;

	/* Calculate the number of hexadecimal digits for the pointer */
	num_len = 0;
	if (addr == 0)
		num_len = 1;
	else
	{
		uintptr_t temp = addr;
		while (temp != 0)
		{
			temp /= 16;
			num_len++;
		}
	}

	/* Account for '0x' prefix */
	num_len += 2;

	/* Calculate padding needed */
	padding = (width > num_len) ? (width - num_len) : 0;

	/* Print padding spaces before the number */
	while (padding-- > 0)
		count += _putchar(' ');

	/* Print '0x' prefix */
	count += _puts("0x");

	/* Print the address in hexadecimal format */
	count += print_hex_lower(addr, flag, width);

	return (count);
}
