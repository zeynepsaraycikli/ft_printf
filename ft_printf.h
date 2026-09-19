#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> // va_list, va_start, va_arg, va_end işlemleri için gerekli kütüphane
# include <unistd.h> // write() fonksiyonu için gerekli kütüphane

/* 
** Ana ft_printf fonksiyonumuz. 
** 'format' stringi yazdırılacak ana metni, '...' ise değişken sayıdaki argümanları ifade eder.
*/
int	ft_printf(const char *format, ...);

/* 
** Karakter ve string yazdırma fonksiyonları (ft_print_chars.c) 
*/
int	ft_print_char(int c);
int	ft_print_string(char *str);

/* 
** Sayı (integer) yazdırma fonksiyonları (ft_print_numbers.c) 
*/
int	ft_print_number(int n);
int	ft_print_unsigned(unsigned int n);

/* 
** Hexadecimal (16'lık taban) ve Pointer yazdırma fonksiyonları (ft_print_hex.c) 
*/
int	ft_print_hex(unsigned int num, int is_upper);
int	ft_print_pointer(unsigned long long ptr);

#endif

