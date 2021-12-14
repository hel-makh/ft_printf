/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pourcentage.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 20:55:31 by hel-makh          #+#    #+#             */
/*   Updated: 2021/11/20 20:55:32 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "includes/ft_printf.h"

size_t	print_pourcentage(t_flags flags)
{
	size_t	char_num;

	char_num = 1;
	if (flags.dash)
		write(1, "%%", 1);
	if (flags.dash && flags.zero)
	{
		flags.width = flags.zero;
		flags.zero = 0;
	}
	while (flags.zero - 1 > 0)
	{
		char_num += write(1, "0", 1);
		flags.zero --;
	}
	while (flags.width - 1 > 0)
	{
		char_num += write(1, " ", 1);
		flags.width --;
	}
	if (!flags.dash)
		write(1, "%%", 1);
	return (char_num);
}
