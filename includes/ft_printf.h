/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 10:38:17 by hel-makh          #+#    #+#             */
/*   Updated: 2021/11/20 10:38:19 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_flags {
	int	dash;
	int	zero;
	int	dot;
	int	width;
	int	sharp;
	int	space;
	int	plus;
	int	dontprint;
}	t_flags;

int		ft_printf(const char *format, ...);
int		is_conversion(char c);
t_flags	manage_flags_combination(const char *format);
size_t	print_char(char c, t_flags flags);
size_t	print_string(const char *format, size_t n, char *str, t_flags flags);
size_t	print_integer(const char *format, size_t n, int nb, t_flags flags);
size_t	print_hex(const char *format, size_t n, void *nb, t_flags flags);
size_t	print_pourcentage(t_flags flags);

size_t	ft_putnchar(char c, int n);
size_t	ft_strlen(const char *s);
size_t	ft_putnstr(const char *str, size_t n);
size_t	ft_nblen(long n, int count_sign);
size_t	ft_putnbr(long nb, int reset_count);
size_t	ft_hexlen(unsigned long n);
size_t	ft_puthex(long nbr, char conversion);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

#endif