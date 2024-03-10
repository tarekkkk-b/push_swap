/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:52:31 by tabadawi          #+#    #+#             */
/*   Updated: 2024/03/10 16:45:59 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	do_push(char *move, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(move, "pa\n") == 0)
		pa(stack_a, stack_b, 0);
	if (ft_strcmp(move, "pb\n") == 0)
		pb(stack_a, stack_b, 0);
}

void	do_swap(char *move, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(move, "sa\n") == 0)
		sa(stack_a, 0);
	if (ft_strcmp(move, "sb\n") == 0)
		sb(stack_b, 0);
	if (ft_strcmp(move, "ss\n") == 0)
		ss(stack_a, stack_b, 0);
}

void	do_rot(char *move, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(move, "ra\n") == 0)
		ra(stack_a, 0);
	if (ft_strcmp(move, "rb\n") == 0)
		rb(stack_b, 0);
	if (ft_strcmp(move, "rr\n") == 0)
		rr(stack_a, stack_b, 0);
}

void	do_revrot(char *move, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(move, "rra\n") == 0)
		rra(stack_a, 0);
	if (ft_strcmp(move, "rrb\n") == 0)
		rrb(stack_b, 0);
	if (ft_strcmp(move, "rrr\n") == 0)
		rrr(stack_a, stack_b, 0);
}
