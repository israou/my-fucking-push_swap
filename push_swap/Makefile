# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 16:58:42 by ichaabi           #+#    #+#              #
#    Updated: 2024/01/28 21:55:46 by ichaabi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_B = checker

CC = CC

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = 	affichage.c \
		atoi.c \
		bigsort.c \
		compare_put.c \
		duplicate.c \
		ft_split.c \
		ft_strjoin.c \
		linkedutils.c \
		moves.c \
		operations.c \
		parsing.c \
		push_swap.c \
		sort3_5.c \
		utils_4_sort.c

SRC_B =	../bonus/parsing_checker.c \
		../bonus/compare_put.c \
		../bonus/checker_duplicate.c \
		../bonus/checker_linked_utils.c \
		../bonus/checker_operations.c \
		../bonus/checker_utils_gnl.c \
		../bonus/checker_gnl.c		\
		../bonus/checker_bonus.c \
		../bonus/split_4checker.c \
		../bonus/join4checker.c \

OBJ = $(SRC:.c=.o)

OBJB = $(SRC_B:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

bonus: $(OBJB)
		$(CC) $(OBJB) -o $(NAME_B)

%.o : %.c ../bonus/checker_bonus.h
		$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(OBJB)

fclean: clean
	$(RM) $(NAME) $(NAME_B)

re: fclean all

.PHONY: all clean fclean re