/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 22:18:35 by hel-makh          #+#    #+#             */
/*   Updated: 2021/11/22 22:18:36 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>
#include "../includes/ft_printf.h"

static size_t	ft_puthex_convert(unsigned long nbr, char *base)
{
	char			base_chars[33];
	unsigned long	quotient;
	unsigned long	remainder;
	int				i;
	size_t			char_num;

	char_num = 0;
	i = 0;
	quotient = nbr;
	while (quotient != 0)
	{
		remainder = quotient % 16;
		base_chars[i++] = base[remainder];
		quotient /= 16;
	}
	base_chars[i--] = '\0';
	while (i >= 0)
		char_num += write(1, &base_chars[i--], 1);
	return (char_num);
}

size_t	ft_puthex(long nbr, char conversion)
{
	size_t	char_num;

	char_num = 0;
	if (nbr == 0)
	{
		nbr += 48;
		char_num += write(1, &nbr, 1);
		return (char_num);
	}
	if (conversion == 'x' || conversion == 'p')
		char_num += ft_puthex_convert(nbr, "0123456789abcdef");
	else if (conversion == 'X')
		char_num += ft_puthex_convert(nbr, "0123456789ABCDEF");
	return (char_num);
}
