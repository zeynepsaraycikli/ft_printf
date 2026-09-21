/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zesarayc <zesarayc@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 03:53:49 by zesarayc          #+#    #+#             */
/*   Updated: 2026/09/19 19:18:35 by zesarayc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int num, char format)
{
	int		len;
	char	*base;

	len = 0;
	if (format == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (num >= 16)
		len += ft_print_hex(num / 16, format);
	len += ft_print_char(base[num % 16]);
	return (len);
}

static int	ft_print_ptr_hex(unsigned long num)
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

int	ft_print_pointer(void *ptr)
{
	int	len;

	len = 0;
	if (!ptr)
		return (write(1, "(nil)", 5));
	len += ft_print_string("0x");
	len += ft_print_ptr_hex((unsigned long)ptr);
	return (len);
}
