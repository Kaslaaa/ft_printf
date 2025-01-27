# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhanle <marvin@42lausanne.ch>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/01 18:59:18 by mhanle            #+#    #+#              #
#    Updated: 2024/11/01 18:59:19 by mhanle           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = 	ft_printf.c \
		ft_print_chars.c \
		ft_print_signed_nbrs.c \
		ft_print_unsigned_nbrs.c\
		ft_print_hexa_nbrs.c \
		ft_print_ptr.c

OBJS= $(SRCS:%.c=%.o)

CFLAGS = -Wall -Werror -Wextra

all: ${NAME}

${OBJS} : ${SRCS} 
	cc -c $(CFLAGS) $(SRCS)

${NAME} : ${OBJS}
	ar rcs $(NAME) $(OBJS)

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY: all clean fclean re
