/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 22:16:17 by hel-makh          #+#    #+#             */
/*   Updated: 2021/11/22 22:16:18 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/ft_printf.h"

size_t	ft_putnstr(const char *str, size_t n)
{
	size_t	char_num;

	char_num = 0;
	if (!str)
		char_num += ft_putnstr("(null)", n);
	else
	{
		while (*str && char_num < n)
			char_num += write(1, str++, 1);
	}
	return (char_num);
}
