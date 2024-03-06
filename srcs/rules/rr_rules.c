/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_rules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:22:32 by tabadawi          #+#    #+#             */
/*   Updated: 2024/03/06 21:53:08 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	revrot(t_list **stack)
{
	t_list	*temp;
	t_list	*iter;

	if (!stack || !(*stack) || ft_lstsize(*stack) == 1)
		return ;
	iter = (*stack);
	temp = ft_lstlast(*stack);
	ft_lstadd_front(stack, ft_lstnew(temp->content));
	while (iter->next != temp)
		iter = iter->next;
	iter->next = NULL;
	free (temp);
	indexer(stack);
}

void	rra(t_list **stack_a, int flag)
{
	if (!stack_a || !(*stack_a))
		return ;
	revrot(stack_a);
	if (flag == 1)
		write (1, "rra\n", 4);
}

void	rrb(t_list **stack_b, int flag)
{
	if (!stack_b || !(*stack_b))
		return ;
	revrot(stack_b);
	if (flag == 1)
		write (1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b, int flag)
{
	if (stack_a && (*stack_a))
		revrot(stack_a);
	if (stack_a && (*stack_a))
		revrot(stack_b);
	if (flag == 1)
		write (1, "rrr\n", 4);
}


//rra -> Shift down all elements of stack a by 1. The last element becomes the first one.
// rrb -> Shift down all elements of stack b by 1. The last element becomes the first one.

// rrr : rra and rrb at the same time.