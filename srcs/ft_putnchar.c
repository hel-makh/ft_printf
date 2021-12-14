/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 22:26:42 by hel-makh          #+#    #+#             */
/*   Updated: 2021/11/22 22:26:42 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/ft_printf.h"

size_t	ft_putnchar(char c, int n)
{
	size_t	char_num;

	char_num = 0;
	while (n > 0)
	{
		char_num += write(1, &c, 1);
		n --;
	}
	return (char_num);
}
