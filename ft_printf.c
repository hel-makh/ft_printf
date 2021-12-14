/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 10:38:08 by hel-makh          #+#    #+#             */
/*   Updated: 2021/11/20 10:38:09 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "includes/ft_printf.h"

static size_t	ft_print_specifier(const char *format, va_list *f_chars)
{
	t_flags	flags;
	size_t	char_num;
	size_t	i;

	flags = manage_flags_combination(format);
	char_num = 0;
	i = 0;
	while (!is_conversion(format[i]))
		i ++;
	if (format[i] == 'c')
		char_num += print_char(va_arg(*f_chars, int), flags);
	else if (format[i] == 's')
		char_num += print_string(format, ++i, va_arg(*f_chars, char *), flags);
	else if (format[i] == 'd' || format[i] == 'i' || format[i] == 'u')
		char_num += print_integer(format, ++i, va_arg(*f_chars, int), flags);
	else if (format[i] == 'x' || format[i] == 'X' || format[i] == 'p')
		char_num += print_hex(format, ++i, va_arg(*f_chars, void *), flags);
	else if (format[i] == '%')
		char_num += print_pourcentage(flags);
	return (char_num);
}

int	ft_printf(const char *format, ...)
{
	va_list	f_chars;
	size_t	char_num;
	size_t	i;

	va_start(f_chars, format);
	char_num = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			char_num += ft_print_specifier(&format[++i], &f_chars);
			while (!is_conversion(format[i]))
				i ++;
			if (is_conversion(format[i]))
				i ++;
			continue ;
		}
		char_num += write(1, &format[i], 1);
		i ++;
	}
	va_end(f_chars);
	return (char_num);
}
