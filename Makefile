# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/31 16:34:18 by tabadawi          #+#    #+#              #
#    Updated: 2024/02/21 18:31:55 by tabadawi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRC	=	ft_atoi.c is_smth.c ft_strjoin.c parsing.c \
		push_swap.c ft_split.c utils.c utils2.c ft_lstnew.c \
		ft_lstadd_back.c ft_lstlast.c ft_lstclear.c ft_lstdelone.c \
		p_rules.c ft_lstadd_front.c s_rules.c

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