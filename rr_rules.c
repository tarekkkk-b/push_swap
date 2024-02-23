/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_rules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:22:32 by tabadawi          #+#    #+#             */
/*   Updated: 2024/02/23 16:53:23 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	revrot(t_list **stack)
{
	t_list	*temp;
	t_list	*iter = (*stack);
	
	temp = ft_lstlast(*stack);
	ft_lstadd_front(stack, ft_lstnew(temp->content));
	while (iter->next != temp)
		iter = iter->next;
	iter->next = NULL;
	free (temp);
}

// t_list	rra(t_list **stack_a)
// {
	
// }

// t_list	rrb(t_list **stack_b)
// {
	
// }

// t_list	rrr(t_list **stack_a, t_list **stack_b)
// {
	
// }


//rra -> Shift down all elements of stack a by 1. The last element becomes the first one.
// rrb -> Shift down all elements of stack b by 1. The last element becomes the first one.

// rrr : rra and rrb at the same time.