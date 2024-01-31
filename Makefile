NAME = push_swap

CC = cc

CFLAGS = #-Wall -Werror -Wextra

SRC	=	atoi.c ismsth.c join.c parsing.c \
		main.c split.c utils.c utils2.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re