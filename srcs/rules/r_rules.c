/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rules.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:15:23 by tabadawi          #+#    #+#             */
/*   Updated: 2024/03/05 19:52:50 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rot(t_list **stack)
{
	t_list	*temp;
	t_list	*last;

	temp = (*stack);
	(*stack) = (*stack)->next;
	last = (*stack);
	while (last->next)
		last = last->next;
	ft_lstadd_back(&last, temp);
	temp->next = NULL;
	// last->next = temp;
	// temp->next = NULL;
	// t_list	*iter = (*stack);
	// temp = (*stack);
	// while (*stack)
	// 	(*stack) = (*stack)->next;
}

void	ra(t_list **stack_a, int flag)
{
	if (!stack_a || !(*stack_a))
		return ;
	rot(stack_a);
	if (flag == 1)
		write (1, "ra\n", 3);
}

void	rb(t_list **stack_b, int flag)
{
	if (!stack_b || !(*stack_b))
		return ;
	rot(stack_b);
	if (flag == 1)
		write (1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b, int flag)
{
	if (stack_a && (*stack_a))
		rot(stack_a);
	if (stack_b && (*stack_b))
		rot(stack_b);
	if (flag == 1)
		write (1, "rr\n", 3);
}

// ra -> Shift up all elements of stack a by 1. The first element becomes the last one.
// rb -> Shift up all elements of stack b by 1. The first element becomes the last one.
// rr : ra and rb at the same time.