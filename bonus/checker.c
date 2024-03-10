/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:25:30 by tabadawi          #+#    #+#             */
/*   Updated: 2024/03/10 18:29:55 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	move_redirect(t_list **stack_a, t_list **stack_b, char *move)
{
	if (ft_strcmp(move, "pa\n") == 0 || ft_strcmp(move, "pb\n") == 0)
		do_push(move, stack_a, stack_b);
	else if (ft_strcmp(move, "sa\n") == 0 || ft_strcmp(move, "sb\n") == 0
		|| ft_strcmp(move, "ss\n") == 0)
		do_swap(move, stack_a, stack_b);
	else if (ft_strcmp(move, "ra\n") == 0 || ft_strcmp(move, "rb\n") == 0
		|| ft_strcmp(move, "rr\n") == 0)
		do_rot(move, stack_a, stack_b);
	else if (ft_strcmp(move, "rra\n") == 0 || ft_strcmp(move, "rrb\n") == 0
		|| ft_strcmp(move, "rrr\n") == 0)
		do_revrot(move, stack_a, stack_b);
	else
	{
		free (move);
		ft_lstclear(stack_a, free);
		if (stack_b)
			ft_lstclear(stack_b, free);
		write (2, "Error\n", 6);
		exit (1);
	}
}

void	read_moves(t_list **stack_a, t_list **stack_b)
{
	char	*move;

	move = get_next_line(0);
	while (move != NULL)
	{
		move_redirect(stack_a, stack_b, move);
		free(move);
		move = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		listsize;
	int		*intarr;

	listsize = 0;
	if (ac < 2)
		exit (0);
	stack_a = NULL;
	intarr = input_handling(av, ac - 1, &listsize);
	stack_a = stackmaker(intarr, listsize, stack_a);
	stack_b = NULL;
	read_moves(&stack_a, &stack_b);
	if (stackissorted(&stack_a) == 0 && ft_lstsize(stack_b) == 0)
		write (1, "OK\n", 3);
	else if (stackissorted(&stack_a) == 1 || ft_lstsize(stack_b) != 0)
		write (1, "KO\n", 3);
	ft_lstclear(&stack_a, free);
	if (stack_b)
		ft_lstclear(&stack_b, free);
	return (0);
}
