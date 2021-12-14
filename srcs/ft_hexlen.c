/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 22:17:23 by hel-makh          #+#    #+#             */
/*   Updated: 2021/11/22 22:17:24 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>
#include "../includes/ft_printf.h"

size_t	ft_hexlen(unsigned long n)
{
	size_t	hexlen;

	hexlen = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		hexlen ++;
	}
	return (hexlen);
}
