# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcastro- <dcastro-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/28 15:46:39 by dcastro-          #+#    #+#              #
#    Updated: 2024/02/28 20:20:13 by dcastro-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS	=	ft_printf.c\
			ft_printf_utils.c\
			src/ft_itoa_base.c\
			src/ft_itoa_unsigned.c\
			src/ft_ptr_conv.c\

OBJS	=	$(SRCS:.c=.o)

#*OBJS	=	ft_printf.o\
			ft_printf_utils.o\
			src/ft_itoa_base.o\
			src/ft_itoa_unsigned.o\
			src/ft_ptr_conv.o\*#

HEADER	=	./includes/ft_printf.h

CFLAGS	= 	-Wall -Wextra -Werror

.c.o:	$(SRCS)
		cc $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS) $(HEADER)
		ar rcs $@ $^

all:	$(NAME)

clean:
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re:		clean all

.PHONY: all clean fclean re