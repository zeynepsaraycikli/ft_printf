*This project has been created as part of the 42 curriculum by zesarayc.*

## Description

This project aims to recreate the behavior of the standard C library function `printf()`. It is an essential part of the 42 curriculum designed to introduce and master the concept of **variadic functions** (functions that take a variable number of arguments using `<stdarg.h>`).

The primary goal is to build a robust, reusable static library (`libftprintf.a`) that handles formatted output seamlessly across various data types while managing memory, error handling, and character counting precisely like the original `printf`.

### Features

`ft_printf` supports the following conversion specifiers:
* `%c`: Prints a single character.
* `%s`: Prints a string.
* `%p`: Prints a void pointer address in hexadecimal format (with `0x`).
* `%d` / `%i`: Prints a signed decimal integer.
* `%u`: Prints an unsigned decimal integer.
* `%x`: Prints a lowercase hexadecimal number.
* `%X`: Prints an uppercase hexadecimal number.
* `%%`: Prints a literal `%` character.

---

## Algorithm and Data Structure

### Algorithm
The core engine of `ft_printf` relies on a **sequential parsing loop**:
1. **String Traversal:** The format string is scanned character by character from left to right.
2. **Literal Printing:** Regular characters (anything that is not `%`) are written directly to standard output (`stdout`), and a character counter is incremented.
3. **Specifier Detection:** When a `%` symbol is encountered, the algorithm evaluates the next character to determine the target format specifier.
4. **Argument Extraction:** A dispatcher handles the matching specifier, extracts the corresponding argument from the stack using `va_arg`, and routes it to dedicated formatting/printing helper functions (e.g., base conversion for hexadecimals, digit counting for integers).
5. **Return Value:** The function returns the total number of characters successfully printed, or `-1` if a write error occurs.

### Data Structure
While `ft_printf` does not implement traditional complex data structures (like linked lists or trees), it relies heavily on **`va_list`** (a pointer-like construct defined in `<stdarg.h>`) to safely traverse and retrieve variable arguments from the memory stack.

---

## Instructions

### Compilation and Installation
The project includes a `Makefile` to automate the build process and generate the static library (`libftprintf.a`).

* **Compile the library:**
  ```bash
  make
  ```
* **Remove object files:**
  ```bash
  make clean
  ```
* **Remove object files and the static library:**
  ```bash
  make fclean
  ```
* **Recompile from scratch:**
  ```bash
  make re
  ```

### Usage / Execution
To use `ft_printf` in your own C programs, include its header and link the generated archive during compilation:

```c
#include "include/ft_printf.h"

int main(void)
{
    ft_printf("Hello %s! Number: %d, Hex: %x\n", "World", 42, 255);
    return (0);
}
```

Compile your program with:
```bash
cc main.c libftprintf.a -o program
./program
```

---

## Resources

### References and Documentation
* [Man page for printf](https://man7.org/linux/man-pages/man3/printf.3.html)
* [GNU C Library - Variadic Functions](https://www.gnu.org/software/libc/manual/html_node/Variadic-Functions.html)
* 42 Project Subject Guidelines (`ft_printf`)

### AI Usage Description
Artificial Intelligence (AI) tools were used during this project for the following specific tasks:
* **Debugging & Edge Cases:** Clarifying how standard `printf` behaves under specific edge conditions (e.g., handling `NULL` pointer strings or negative hex formatting).
* **Documentation Structuring:** Assisting in drafting and organizing the sections of this `README.md` to ensure full compliance with the 42 curriculum criteria.
* *Note:* All implementation details, parsing logic, and source code were written, tested, and debugged manually.