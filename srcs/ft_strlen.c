/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 22:15:10 by hel-makh          #+#    #+#             */
/*   Updated: 2021/11/22 22:15:11 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	strlen;

	strlen = 0;
	if (!s)
		return (ft_strlen("(null)"));
	while (s[strlen] != '\0')
		strlen ++;
	return (strlen);
}
