# ft_printf

This project aims to recreate the behavior of the standard C library function `printf()`. It is a part of the 42 curriculum and designed to introduce the concept of **variadic functions** (functions that take a variable number of arguments).

## Features

This `ft_printf` project supports the following format specifiers:

- `%c`: Prints a single character.
- `%s`: Prints a string (array of characters).
- `%p`: Prints the memory address of a void pointer in hexadecimal format (with a `0x` prefix).
- `%d`: Prints a signed decimal (base 10) integer.
- `%i`: Prints a signed decimal (base 10) integer (functions identically to `%d`).
- `%u`: Prints an unsigned decimal (base 10) integer.
- `%x`: Prints an unsigned hexadecimal (base 16) number in lowercase format.
- `%X`: Prints an unsigned hexadecimal (base 16) number in uppercase format.
- `%%`: Prints a literal `%` character.

## Project Structure

- `include/ft_printf.h`: The header file containing the function prototypes.
- `src/`: The directory containing the C source files.
- `Makefile`: Automates the compilation process and creates the `libftprintf.a` static library.

## Installation and Usage

### 1. Compiling the Library
After cloning or downloading the project, navigate to the directory in your terminal and run the following command to create the static library (`libftprintf.a`):
```bash
make
```

### 2. Using it in your own project
Once `libftprintf.a` is generated, you can use the `ft_printf` function in your C programs.

An example `main.c` file:
```c
#include "include/ft_printf.h"

int main(void)
{
    ft_printf("Hello %s! Number: %d, Hex: %x\n", "World", 42, 255);
    return (0);
}
```

To compile your code with the library:
```bash
cc main.c libftprintf.a -o program
./program
```

## Makefile Commands

- `make` or `make all`: Compiles the source files and creates the `libftprintf.a` archive.
- `make clean`: Removes the object (`.o`) files generated during compilation.
- `make fclean`: Removes the object files as well as the `libftprintf.a` library.
- `make re`: Fully cleans the project and recompiles it from scratch (`fclean` + `all`).
