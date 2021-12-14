/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 20:55:08 by hel-makh          #+#    #+#             */
/*   Updated: 2021/11/20 20:55:09 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "includes/ft_printf.h"

static size_t	ft_right_adjust(long nb, size_t len, t_flags *flags)
{
	size_t	char_num;

	char_num = 0;
	if (flags->zero && (int)len < flags->zero)
		len = flags->zero;
	if (nb < 0 && (len != ft_nblen(nb, 1) || (int)len == flags->zero))
		len ++;
	if (flags->dontprint)
		flags->width ++;
	char_num += ft_putnchar(' ', flags->width - (int)len - flags->plus);
	if (flags->plus)
		char_num += ft_putnchar('+', 1);
	else if (nb >= 0 && flags->space && char_num == 0)
		char_num += ft_putnchar(' ', 1);
	if (!flags->dot && (flags->plus || (nb > 0 && flags->space)))
		flags->zero -= 1;
	if (nb < 0)
		char_num += ft_putnchar('-', 1);
	char_num += ft_putnchar('0',
			flags->zero - (int)ft_nblen(nb, !flags->dot));
	if (nb < 0)
		nb *= -1;
	if (!flags->dontprint)
		char_num += ft_putnbr(nb, 1);
	return (char_num);
}

static size_t	ft_left_adjust(long nb, size_t len, t_flags *flags)
{
	size_t	char_num;

	char_num = 0;
	len = 0;
	if (flags->plus)
		char_num += ft_putnchar('+', 1);
	else if (nb >= 0 && flags->space)
		char_num += ft_putnchar(' ', 1);
	if (nb < 0)
		char_num += ft_putnchar('-', 1);
	char_num += ft_putnchar('0', flags->zero - (int)ft_nblen(nb, 0));
	if (nb < 0)
		nb *= -1;
	if (!flags->dontprint)
		char_num += ft_putnbr(nb, 1);
	char_num += ft_putnchar(' ', flags->width - char_num);
	return (char_num);
}

static void	ft_manage_padding(
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
	else if (ft_strnstr(format, ".d", n) || ft_strnstr(format, ".0d", n)
		|| ft_strnstr(format, ".i", n) || ft_strnstr(format, ".0i", n)
		|| ft_strnstr(format, ".u", n) || ft_strnstr(format, ".0u", n))
	{
		if (flags->zero && !flags->dot)
		{
			flags->width = flags->zero;
			flags->zero = 0;
		}
		if (nb == 0)
			flags->dontprint = 1;
	}
	if (flags->plus && flags->space)
		flags->space = 0;
}

size_t	print_integer(const char *format, size_t n, int nb, t_flags flags)
{
	size_t	char_num;
	size_t	len;
	long	lnb;

	char_num = 0;
	lnb = nb;
	if (format[n - 1] == 'u')
		lnb = (unsigned int)nb;
	if (flags.plus && lnb < 0)
		flags.plus = 0;
	ft_manage_padding(format, n, lnb, &flags);
	len = ft_nblen(lnb, 0);
	if (flags.dash)
		char_num += ft_left_adjust(lnb, len, &flags);
	else
		char_num += ft_right_adjust(lnb, len, &flags);
	return (char_num);
}
