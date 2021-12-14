SRCSDIR			=	srcs

INCDIR			=	./includes

HEADER			=	$(INCDIR)/ft_printf.h

NAME			=	libftprintf.a

SRCS			=	ft_printf.c\
					ft_printf_flags_management.c\
					ft_print_char.c\
					ft_print_string.c\
					ft_print_integer.c\
					ft_print_hexadecimal.c\
					ft_print_pourcentage.c\
					$(SRCSDIR)/ft_putnchar.c\
					$(SRCSDIR)/ft_strlen.c\
					$(SRCSDIR)/ft_putnstr.c\
					$(SRCSDIR)/ft_nblen.c\
					$(SRCSDIR)/ft_putnbr.c\
					$(SRCSDIR)/ft_hexlen.c\
					$(SRCSDIR)/ft_puthex.c\
					$(SRCSDIR)/ft_strnstr.c

OBJS			=	$(SRCS:.c=.o)

GCC				=	cc

CFLAGS			=	-Wall -Wextra -Werror

RM				=	rm -f

.c.o:
				$(GCC) $(CFLAGS) -I$(INCDIR) -c $< -o $(<:.c=.o)

$(NAME):		$(OBJS) $(HEADER)
				ar rc $@ $^
				ranlib $@

bonus:			$(OBJS) $(HEADER)
				ar rc $(NAME) $^
				ranlib $(NAME)

all:			$(NAME)

clean:
				$(RM) $(OBJS)
			
fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all bonus clean fclean re