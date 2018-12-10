# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pimichau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 13:12:08 by pimichau          #+#    #+#              #
#    Updated: 2018/12/10 11:41:44 by pimichau         ###   ########.fr        #
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

$(NAME): $(OBJS)
		$(CC) -o $(NAME) $(OBJS) libft/libft.a

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean $(CLEAN) fclean re
