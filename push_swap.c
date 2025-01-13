/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:24:42 by tabadawi          #+#    #+#             */
/*   Updated: 2025/01/13 14:35:09 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_input *var, int ac, char **av)
{
	var->input = join_args(var->input, av, ac);
	var->numbercount = inputcount(var->input, ' ');
	var->sp_inp = ft_split(var->input, ' ');
	free (var->input);
	if (!var->sp_inp)
		exiting(NULL, NULL);
}

int	*input_handling(char **av, int ac, int *list_size)
{
	t_input	var;

	init(&var, ac, av);
	if (!var.sp_inp[0])
		exiting(NULL, var.sp_inp);
	var.intarr = parser(var.sp_inp, var.numbercount, list_size);
	if (!var.intarr)
		exiting(NULL, NULL);
	return (var.intarr);
}

t_list	*stackmaker(int *intarr, int list_size, t_list *node)
{
	int		i;
	t_list	*new;

	i = 0;
	while (i < list_size)
	{
		new = ft_lstnew(intarr[i]);
		if (!new)
		{
			ft_lstclear(&node, free);
			free (intarr);
			write (2, "Error\n", 6);
			exit(1);
		}
		ft_lstadd_back(&node, new);
		i++;
	}
	indexer(&node);
	return (free (intarr), node);
}

void	pushback(t_list **stack_a, t_list **stack_b)
{
	if (!stack_b || !(*stack_b))
		return ;
	while (findmax(stack_b)->i != 0
		&& findmax(stack_b)->i > (ft_lstsize(*stack_b) / 2))
	{
		rrb(stack_b, 1);
		indexer(stack_b);
	}
	while (findmax(stack_b)->i != 0
		&& findmax(stack_b)->i <= (ft_lstsize(*stack_b) / 2))
	{
		rb(stack_b, 1);
		indexer(stack_b);
	}
	if ((*stack_a)->content < (*stack_b)->content)
		while (ft_lstlast(*stack_a)->content > (*stack_b)->content)
			rra(stack_a, 1);
	while (*stack_b)
	{
		pa(stack_a, stack_b, 1);
		while ((*stack_b) && ft_lstlast(*stack_a)->content > (*stack_b)->content
			&& ft_lstlast(*stack_a)->content < (*stack_a)->content)
			rra(stack_a, 1);
	}
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize((*stack_a)) > 3)
	{
		redirect(cheapestcalculater(stack_a, stack_b), stack_a, stack_b);
		pb(stack_a, stack_b, 1);
		indexer(stack_a);
		indexer(stack_b);
	}
	sortthree(stack_a);
	indexer(stack_a);
	pushback(stack_a, stack_b);
}
