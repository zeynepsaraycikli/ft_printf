#include "ft_printf.h"

int	ft_print_hex(unsigned int num, int is_upper)
{
	int		len;
	char	*base;

	len = 0;
	if (is_upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef"; 
	if (num >= 16)
		len += ft_print_hex(num / 16, is_upper);
	len += ft_print_char(base[num % 16]);
	return (len);
}

static int	ft_print_ptr_hex(unsigned long long num)
{
	int		len;
	char	*base;

	len = 0;
	base = "0123456789abcdef";
	
	if (num >= 16)
		len += ft_print_ptr_hex(num / 16);
		
	len += ft_print_char(base[num % 16]);
	return (len);
}

int	ft_print_pointer(unsigned long long ptr)
{
	int	len;

	len = 0;
	len += ft_print_string("0x");
	len += ft_print_ptr_hex(ptr);
	return (len);
}

