/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 22:11:40 by hel-makh          #+#    #+#             */
/*   Updated: 2021/11/22 22:11:41 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/ft_printf.h"

size_t	ft_putnbr(long nb, int reset_count)
{
	static size_t	char_num;

	if (reset_count)
		char_num = 0;
	if (nb < 0)
	{
		nb = -nb;
		char_num += write(1, "-", 1);
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10, 0);
		ft_putnbr(nb % 10, 0);
	}
	else
	{
		nb += '0';
		char_num += write(1, &nb, 1);
	}
	return (char_num);
}
