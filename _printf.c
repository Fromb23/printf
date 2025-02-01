#include <stdarg.h>
#include <unistd.h>

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
 * print_string - Handles %s specifier for printing strings
 * @str: The string to be printed
 *
 * Return: The number of characters printed
 */
int print_string(char *str)
{
	int count = 0;

	while (str[count] != '\0')
	{
		_putchar(str[count]);
		count++;
	}
	return (count);
}

/**
 * print_char - Handles %c specifier for printing a character
 * @ch: The character to be printed
 *
 * Return: 1 (number of characters printed)
 */
int print_char(char ch)
{
	_putchar(ch);
	return (1);
}

/**
 * print_percent - Handles %% specifier for printing a percent symbol
 *
 * Return: 1 (number of characters printed)
 */
int print_percent(void)
{
	_putchar('%');
	return (1);
}

/**
 * _printf - Custom printf function that handles %s, %c, and %%
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
			if (*(ptr + 1) == 's' || *(ptr + 1) == 'c' || *(ptr + 1) == '%')
			{
				if (*(ptr + 1) == 's')
				{
					char *str = va_arg(args, char *);

					count += print_string(str);
				}
				else if (*(ptr + 1) == 'c')
				{
					char ch = (char)va_arg(args, int);

					count += print_char(ch);
				}
				else if (*(ptr + 1) == '%')
				{
					count += print_percent();
				}
				ptr++;  /* Skip the specifier */
			}
			else
			{
				_putchar(*ptr);
				count++;
			}
		}
	}

	va_end(args);
	return (count);
}
