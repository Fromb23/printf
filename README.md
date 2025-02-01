# Custom `printf` Function Documentation

## Introduction
This document provides an overview of the custom `printf` function, which is designed to mimic the behavior of the standard `printf` function in C. The custom `printf` function supports a subset of format specifiers and demonstrates how formatted output can be implemented from scratch.

## Features
The custom `printf` function supports the following format specifiers:
- `%c`: Print a single character.
- `%s`: Print a string.
- `%d` or `%i`: Print a signed integer.
- `%u`: Print an unsigned integer.
- `%o`: Print an unsigned integer in octal format.
- `%x` or `%X`: Print an unsigned integer in hexadecimal format (lowercase or uppercase).
- `%p`: Print a pointer address.
- `%%`: Print a literal `%` character.

Additional features:
- Basic formatting flags (e.g., width, precision) are supported.
- The function handles edge cases such as `NULL` pointers and invalid format specifiers.

## How It Works
The custom `printf` function parses the format string and processes each format specifier sequentially. For each specifier, it extracts the corresponding argument from the variadic argument list (`va_list`) and formats it according to the specified rules.

### Key Components
1. **Variadic Arguments**:
   - The function uses the `stdarg.h` library to handle a variable number of arguments.
   - The `va_list`, `va_start`, `va_arg`, and `va_end` macros are used to access the arguments.

2. **Format Specifier Parsing**:
   - The function iterates through the format string and identifies format specifiers using the `%` character.
   - Each specifier is processed based on its type (e.g., `%d` for integers, `%s` for strings).

3. **Output Handling**:
   - The formatted output is written to the standard output (stdout) using the `write` system call or a buffer.

4. **Edge Cases**:
   - The function handles edge cases such as invalid specifiers, `NULL` strings, and missing arguments.

## Example Usage
Below is an example of how to use the custom `printf` function:

```c
#include "custom_printf.h"

int main() {
    custom_printf("Hello, %s!\n", "World");
    custom_printf("The number is %d\n", 42);
    custom_printf("Hex: %x, Octal: %o\n", 255, 255);
    custom_printf("Pointer: %p\n", (void *)0x7ffee4b6a8d0);
    custom_printf("Character: %c\n", 'A');
    custom_printf("Percent sign: %%\n");
    return 0;
}
