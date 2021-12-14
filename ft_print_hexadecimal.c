/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexadecimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 20:55:23 by hel-makh          #+#    #+#             */
/*   Updated: 2021/11/20 20:55:24 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "includes/ft_printf.h"

static size_t	ft_hright_adjust(long nb, char conv, size_t len, t_flags *flags)
{
	size_t	char_num;

	char_num = 0;
	if (flags->zero && (int)len < flags->zero)
		len = flags->zero;
	if (conv == 'p' || (flags->sharp && nb != 0))
		flags->width -= 2;
	if (flags->dontprint)
		flags->width ++;
	char_num += ft_putnchar(' ', flags->width - (int)len);
	if (conv == 'p' || (flags->sharp && nb != 0))
	{
		if (conv == 'X')
			char_num += write(1, "0X", 2);
		else
			char_num += write(1, "0x", 2);
		if (!flags->dot)
			flags->zero -= 2;
	}
	if (conv != 'p')
		char_num += ft_putnchar('0', flags->zero - (int)ft_hexlen(nb));
	if (!flags->dontprint)
		char_num += ft_puthex(nb, conv);
	return (char_num);
}

static size_t	ft_hleft_adjust(long nb, char conv, size_t len, t_flags *flags)
{
	size_t	char_num;

	char_num = 0;
	len = 0;
	if (conv == 'p' || (flags->sharp && nb != 0))
	{
		if (conv == 'X')
			char_num += write(1, "0X", 2);
		else
			char_num += write(1, "0x", 2);
		if (!flags->dot)
			flags->zero -= 2;
	}
	if (conv != 'p')
		char_num += ft_putnchar('0', flags->zero - (int)ft_hexlen(nb));
	if (!flags->dontprint)
		char_num += ft_puthex(nb, conv);
	char_num += ft_putnchar(' ', flags->width - char_num);
	return (char_num);
}

static void	ft_hmanage_padding(
	const char *format, size_t n, long nb, t_flags *flags
)
{
	if (flags->dot && !flags->zero)
	{
		flags->zero = flags->dot;
		flags->dot = 1;
	}
	else if (flags->dot && flags->zero)
	{
		flags->width = flags->zero;
		flags->zero = flags->dot;
		flags->dot = 1;
	}
	else if (ft_strnstr(format, ".x", n) || ft_strnstr(format, ".0x", n)
		|| ft_strnstr(format, ".X", n) || ft_strnstr(format, ".0X", n))
	{
		if (flags->zero && !flags->dot)
		{
			flags->width = flags->zero;
			flags->zero = 0;
		}
		if (nb == 0)
			flags->dontprint = 1;
	}
}

size_t	print_hex(const char *format, size_t n, void *nb, t_flags flags)
{
	size_t	char_num;
	size_t	len;
	long	lnb;

	char_num = 0;
	lnb = 0;
	if (format[n - 1] == 'x' || format[n - 1] == 'X')
		lnb = (unsigned int)nb;
	else if (format[n - 1] == 'p')
		lnb = (unsigned long)nb;
	ft_hmanage_padding(format, n, lnb, &flags);
	len = ft_hexlen(lnb);
	if (flags.dash)
		char_num += ft_hleft_adjust(lnb, format[n - 1], len, &flags);
	else
		char_num += ft_hright_adjust(lnb, format[n - 1], len, &flags);
	return (char_num);
}
