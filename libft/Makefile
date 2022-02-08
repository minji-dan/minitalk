# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkim2 <mkim2@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/08 16:19:53 by mkim2             #+#    #+#              #
#    Updated: 2022/02/08 16:53:10 by mkim2            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

NAME		=	libft.a
SRCS		=	ft_strlen.c \
				ft_atoi.c \
				ft_isdigit.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putnbr_fd.c

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	ar -cr $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
