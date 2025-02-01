#include "main.h"
#include <stdint.h>

/**
 * print_pointer - Prints a memory address in hexadecimal format
 * @ptr: The pointer to be printed
 *
 * Return: Number of characters printed
 */
int print_pointer(void *ptr)
{
	uintptr_t addr;
	int count = 0;

	if (!ptr)
		return (_puts("(nil)")); /* Handle NULL pointer */

	addr = (uintptr_t)ptr;
	count += _puts("0x"); /* Print '0x' prefix */
	count += print_hex_lower(addr); /* Convert to hex */

	return (count);
}
