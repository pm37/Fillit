# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pimichau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 13:12:08 by pimichau          #+#    #+#              #
#    Updated: 2018/12/11 14:41:03 by pimichau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = $(wildcard *.c)

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
