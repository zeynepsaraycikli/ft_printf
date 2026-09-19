#include "ft_printf.h"

static int	ft_format(va_list args, const char format)
{
	int	printed_len;

	printed_len = 0;
	if (format == 'c')
		printed_len += ft_print_char(va_arg(args, int));
	else if (format == 's')
		printed_len += ft_print_string(va_arg(args, char *));
	else if (format == 'p')
		printed_len += ft_print_pointer(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		printed_len += ft_print_number(va_arg(args, int));
	else if (format == 'u')
		printed_len += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x')
		printed_len += ft_print_hex(va_arg(args, unsigned int), 0);
	else if (format == 'X')
		printed_len += ft_print_hex(va_arg(args, unsigned int), 1);
	else if (format == '%')
		printed_len += ft_print_char('%');
	return (printed_len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		total_len;
	va_list	args;

	i = 0;
	total_len = 0;
	va_start(args, format);	
	while (format[i])
	{
		if (format[i] == '%')
		{
			total_len += ft_format(args, format[i + 1]);
			i++;
		}
		else
		{
			total_len += ft_print_char(format[i]);
		}
		i++;
	}
	va_end(args);
	return (total_len); 
}

