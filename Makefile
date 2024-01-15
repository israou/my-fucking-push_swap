# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 16:10:34 by ichaabi           #+#    #+#              #
#    Updated: 2024/01/14 20:04:35 by ichaabi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = CC

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = push_swap.c begin1.c ft_split.c ft_strjoin.c Checking.c duplicate.c ft_strlen.c operations.c linkedutils.c utils_4_sort.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o : %.c push_swap.h
		$(CC) $(CFLAGS) -c $<

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all
