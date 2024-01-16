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
		sorting.c \
		utils_4_sort.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o : %.c push_swap.h
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all