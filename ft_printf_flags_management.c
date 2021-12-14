/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags_management.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:32:36 by hel-makh          #+#    #+#             */
/*   Updated: 2021/11/20 19:32:38 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "includes/ft_printf.h"

int	is_conversion(char c)
{
	return (c == 'c'
		|| c == 's'
		|| c == 'p'
		|| c == 'd'
		|| c == 'i'
		|| c == 'u'
		|| c == 'x'
		|| c == 'X'
		|| c == '%');
}

static void	initialize_flags(t_flags *flags)
{
	flags->dash = 0;
	flags->zero = 0;
	flags->dot = 0;
	flags->width = 0;
	flags->sharp = 0;
	flags->space = 0;
	flags->plus = 0;
	flags->dontprint = 0;
}

static void	manage_flags(const char *format, t_flags *flags)
{
	size_t	i;

	i = 0;
	while (!is_conversion(format[i]))
	{
		if (format[i] == '#')
			flags->sharp = 1;
		if (format[i] == ' ')
			flags->space = 1;
		if (format[i] == '+')
			flags->plus = 1;
		i ++;
	}
}

t_flags	manage_flags_combination(const char *format)
{
	t_flags	flags;
	size_t	i;

	initialize_flags(&flags);
	i = -1;
	while (!is_conversion(format[++i]))
	{
		if (format[i] == '-')
			flags.dash = 1;
		if (format[i] == '0')
			while (!is_conversion(format[i + 1])
				&& format[i + 1] >= '0' && format[i + 1] <= '9'
				&& !flags.dot && !flags.width)
				flags.zero = flags.zero * 10 + format[++i] - '0';
		if (!flags.width)
			while (format[i] >= '0' && format[i] <= '9'
				&& !flags.zero && !flags.dot)
				flags.width = (flags.width * 10) + format[i++] - '0';
		if (format[i] == '.')
			while (!is_conversion(format[i + 1])
				&& format[i + 1] >= '0' && format[i + 1] <= '9')
				flags.dot = flags.dot * 10 + format[++i] - '0';
	}
	manage_flags(format, &flags);
	return (flags);
}
