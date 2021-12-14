/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 20:54:55 by hel-makh          #+#    #+#             */
/*   Updated: 2021/11/20 20:54:56 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "includes/ft_printf.h"

size_t	print_char(char c, t_flags flags)
{
	size_t	char_num;

	char_num = 1;
	if (flags.dash)
		write(1, &c, 1);
	while (flags.width - 1 > 0)
	{
		char_num += write(1, " ", 1);
		flags.width --;
	}
	if (!flags.dash)
		write(1, &c, 1);
	return (char_num);
}
