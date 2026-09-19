#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_print_char(int c);
int	ft_print_string(char *str);
int	ft_print_number(int n);
int	ft_print_unsigned(unsigned int n);
int	ft_print_hex(unsigned int num, int is_upper);
int	ft_print_pointer(unsigned long long ptr);

#endif

