# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pimichau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 13:12:08 by pimichau          #+#    #+#              #
#    Updated: 2019/01/02 17:50:33 by pimichau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = 	srcs/ft_check_file.c 		\
		srcs/ft_check_place.c 		\
		srcs/ft_complete_tetris.c	\
		srcs/ft_init.c				\
		srcs/ft_manipulate_list.c	\
		srcs/main.c

OBJS = $(SRC:.c=.o)

HEAD = srcs/fillit.h

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror

DIR = libft/

all: $(NAME)

$(NAME): $(OBJS) $(HEAD)
		make -C $(DIR) 
		$(CC) -o $(NAME) $(OBJS) $(DIR)libft.a

clean:
		$(RM) $(OBJS)
		make -C $(DIR) clean

fclean: clean
		$(RM) $(NAME)
		make -C $(DIR) fclean

re: fclean all

.PHONY: all clean $(CLEAN) fclean re
