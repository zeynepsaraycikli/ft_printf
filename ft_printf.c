/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zesarayc <zesarayc@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 19:45:41 by zesarayc          #+#    #+#             */
/*   Updated: 2026/09/19 19:20:29 by zesarayc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		printed_len += ft_print_pointer(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		printed_len += ft_print_nbr(va_arg(args, int));
	else if (format == 'u')
		printed_len += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		printed_len += ft_print_hex(va_arg(args, unsigned int), format);
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
