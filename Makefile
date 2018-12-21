# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pimichau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 13:12:08 by pimichau          #+#    #+#              #
#    Updated: 2018/12/21 10:21:47 by pimichau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = 	ft_check_file.c 		\
		ft_check_place.c 		\
		ft_complete_tetris.c	\
		ft_init.c				\
		ft_manipulate_list.c	\
		main.c

OBJS = $(SRC:.c=.o)

HEAD = fillit.h

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) $(HEAD)
		cd libft/ ; make
		$(CC) -o $(NAME) $(OBJS) libft/libft.a

clean:
		$(RM) $(OBJS)
		cd libft/ ; make clean

fclean: clean
		$(RM) $(NAME)
		cd libft/ ; $(RM) libft.a

re: fclean all

.PHONY: all clean $(CLEAN) fclean re
