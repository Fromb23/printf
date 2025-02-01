#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
void specifier_advanced(va_list args, int *count, const char *ptr);
void specifier_basic(va_list args, int *count, const char *ptr);

int _putchar(char ch);
int _puts(char *str);

int print_string(char *str);
int print_char(char ch);
int print_percent(void);
int print_integer(int num);
int print_unsigned(unsigned int n);
int print_octal(unsigned int n);
int print_hex_lower(unsigned int n);
int print_hex_upper(unsigned int n);
int print_custom_string(char *str);
int print_pointer(void *ptr);

#endif
