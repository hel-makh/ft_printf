/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 20:59:10 by hel-makh          #+#    #+#             */
/*   Updated: 2021/11/20 20:59:11 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "includes/ft_printf.h"

size_t	print_string(const char *format, size_t n, char *str, t_flags flags)
{
	size_t	char_num;
	size_t	len;

	char_num = 0;
	len = ft_strlen(str);
	if ((flags.dot && (int)len > flags.dot)
		|| ft_strnstr(format, ".0", n) || ft_strnstr(format, ".s", n))
		len = flags.dot;
	if (flags.dash)
		char_num += ft_putnstr(str, len);
	while (flags.width - (int)len > 0)
	{
		char_num += write(1, " ", 1);
		flags.width --;
	}
	if (!flags.dash)
		char_num += ft_putnstr(str, len);
	return (char_num);
}
