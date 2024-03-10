# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/31 16:34:18 by tabadawi          #+#    #+#              #
#    Updated: 2024/03/10 18:52:49 by tabadawi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS = checker

CC = cc

CFLAGS = -Wall -Werror -Wextra

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
		push_swap.c \
		stack_utils.c \
		sort_utils1.c \
		sort_utils2.c \
		main.c

BONUS_SRC =		utils/ft_atoi.c \
				utils/ft_split.c \
				utils/ft_strjoin.c \
				utils/is_smth.c \
				utils/parsing.c \
				utils/utils2.c \
				utils/utils.c \
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
				push_swap.c \
				stack_utils.c \
				sort_utils1.c \
				sort_utils2.c \
				bonus/checker_utils.c \
				bonus/checker.c \
				bonus/get_next_line/get_next_line.c \
				bonus/get_next_line/get_next_line_utils.c
				
OBJS =	$(SRC:.c=.o)

BONUS_OBJS =	$(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^

bonus:	$(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS)
clean:
	@rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	@rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re
