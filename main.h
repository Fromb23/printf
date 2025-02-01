#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/* Main printf function */
int _printf(const char *format, ...);

/* Specifier handling functions */
void specifier_advanced(va_list args, int *count, const char *ptr);
void specifier_basic(va_list args, int *count, const char *ptr);

/* Character and string output functions */
int _putchar(char ch);
int _puts(char *str);

/* Print functions for different types */
int print_string(char *str);
int print_char(char ch);
int print_percent(void);
int print_integer(int num, char flag);
int print_unsigned(unsigned int num);
int print_octal(unsigned int num, char flag);
int print_hex_lower(unsigned int num, char flag);
int print_hex_upper(unsigned int num, char flag);
int print_custom_string(char *str);
int print_pointer(void *ptr, char flag);

/* Number base conversion functions */
int print_number_base_upper(unsigned int num, int base);
int print_number_base(unsigned int num, int base);

#endif
