# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 16:58:42 by ichaabi           #+#    #+#              #
#    Updated: 2024/01/23 22:07:16 by ichaabi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = CC

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = 	Checking.c \
		begin1.c \
		duplicate.c \
		ft_split.c \
		ft_strjoin.c \
		ft_strlen.c \
		linkedutils.c \
		operations.c \
		push_swap.c \
		sort3_5.c \
		moves.c \
		utils_4_sort.c \
		bigsort.c

BONUS = checker_bonus.c \

OBJ = $(SRC:.c=.o)

OBJB = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

bonus: $(OBJB)
		$(CC) $(OBJB) -o $(NAME)

%.o : %.c push_swap.h
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all