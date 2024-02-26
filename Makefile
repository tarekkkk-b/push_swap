# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/31 16:34:18 by tabadawi          #+#    #+#              #
#    Updated: 2024/02/23 18:34:56 by tabadawi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g3

SRC_DIR = ./srcs/

SRC	=	utils/ft_atoi.c \
		utils/ft_split.c \
		utils/ft_strjoin.c \
		utils/is_smth.c \
		utils/parsing.c \
		utils/utils.c \
		utils/utils2.c \
		lists/ft_lstnew.c \
		lists/ft_lstadd_back.c \
		lists/ft_lstlast.c \
		lists/ft_lstclear.c \
		lists/ft_lstdelone.c \
		lists/ft_lstadd_front.c \
		lists/ft_lstsize.c \
		rules/p_rules.c \
		rules/s_rules.c \
		rules/rr_rules.c \
		rules/r_rules.c \
		push_swap.c

SRC_PATH = $(addprefix $(SRC_DIR), $(SRC))

OBJ = $(SRC:.c=.o)

OBJ_DIR = ./objects/

OBJ_PATH = $(addprefix $(OBJ_DIR), $(OBJ))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(OBJ_PATH) -o $(NAME)
	@echo "push_swap created"

$(OBJ_PATH): $(SRC_PATH)
	@make -s $(OBJ)

$(OBJ):
	@$(CC) $(CFLAGS) $(SRC_DIR)$(@:%.o=%.c) -c -o $(OBJ_DIR)$@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)lists $(OBJ_DIR)utils $(OBJ_DIR)rules

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re