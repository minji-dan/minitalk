# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkim2 <mkim2@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/08 14:53:05 by mkim2             #+#    #+#              #
#    Updated: 2022/02/08 17:13:52 by mkim2            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER			= server
CLIENT			= client

CC				= gcc
CFLAG			= -Wextra -Wall -Werror
RM				= rm -f
AR				= ar cr

SRCS_DIR		= ./srcs/
PRINT_SRCS		= printmsg.c
SV_SRCS			= server.c
CL_SRCS			= client.c
PRINT_OBJS		= $(PRINT_SRCS:.c=.o)
SV_OBJS			= $(SV_SRCS:.c=.o)
CL_OBJS			= $(CL_SRCS:.c=.o)

BSV_SRCS		= server_bonus.c
BCL_SRCS		= client_bonus.c
BSV_OBJS		= $(BSV_SRCS:.c=.o)
BCL_OBJS		= $(BCL_SRCS:.c=.o)

LIBFT			= libft
LIBFT_FLAGS		= -L $(LIBFT) -lft
INC_FLAGS		= -I includes -I $(LIBFT)

ifdef WITH_BONUS
	SV_OBJECTS = $(BSV_OBJS)
	CL_OBJECTS = $(BCL_OBJS)
else
	SV_OBJECTS = $(SV_OBJS)
	CL_OBJECTS = $(CL_OBJS)
endif

all: $(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT):
	@make --silent --directory=$(LIBFT)

$(SERVER): $(SV_OBJECTS) $(PRINT_OBJS)
	$(CC) $(CFLAG) -o $(SERVER) $(SV_OBJECTS) $(PRINT_OBJS) $(LIBFT_FLAGS)

$(CLIENT): $(CL_OBJECTS) $(PRINT_OBJS)
	$(CC) $(CFLAG) -o $(CLIENT) $(CL_OBJECTS) $(PRINT_OBJS) $(LIBFT_FLAGS)

bonus:
	make WITH_BONUS=1 all
 
%.o: $(SRCS_DIR)%.c
	$(CC) $(CFLAG) -c $< -o $@ $(INC_FLAGS)

clean:
	@make clean --silent --directory=$(LIBFT)
	$(RM) $(SV_OBJS) $(CL_OBJS) $(PRINT_OBJS) $(BSV_OBJS) $(BCL_OBJS)

fclean: clean
	@make fclean --silent --directory=$(LIBFT)
	$(RM) $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all bonus clean fclean re $(LIBFT)
