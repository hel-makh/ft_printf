/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 22:10:54 by hel-makh          #+#    #+#             */
/*   Updated: 2021/11/22 22:10:57 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	ft_nblen(long n, int count_sign)
{
	size_t	intlen;

	intlen = 0;
	if (n == 0)
		return (1);
	if (n < 0 && count_sign)
		intlen ++;
	while (n != 0)
	{
		n /= 10;
		intlen ++;
	}
	return (intlen);
}
