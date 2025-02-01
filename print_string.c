#include "main.h"
#include <unistd.h>

/**
 * print_string - Prints a string
 * @str: The string to be printed
 *
 * Return: The number of characters printed
 */
int print_string(char *str)
{
	int count = 0;

	if (str == NULL)
	{
		str = "(null)";
	}

	while (str[count] != '\0')
	{
		_putchar(str[count]);
		count++;
	}

	return (count);
}
