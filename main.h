#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
void specifier(va_list args, int *count, const char *ptr);
int _putchar(char ch);

int print_string(char *str);
int print_char(char ch);
int print_percent(void);
int print_integer(int num);

#endif
