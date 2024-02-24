/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_rules.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:09:24 by tabadawi          #+#    #+#             */
/*   Updated: 2024/02/24 14:52:22 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	int	tmp;

	tmp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp;
	// int		integer1;
	// int		integer2;
	// t_list	*temp1;
	// t_list	*temp2;
	// integer1 = (*stack)->content;
	// temp1 = *stack;
	// *stack = (*stack)->next;
	// free (temp1);
	// integer2 = (*stack)->content;
	// temp2 = *stack;
	// *stack = (*stack)->next;
	// free (temp2);
	// temp1 = ft_lstnew(integer1);
	// temp2 = ft_lstnew(integer2);
	// ft_lstadd_front(stack, temp1);
	// ft_lstadd_front(stack, temp2);
}

void	sa(t_list **stack_a, int flag)
{
	swap(&stack_a);
	if (flag == 1)
		write (1, "sa\n", 1);
}

void	sb(t_list **stack_b, int flag)
{
	swap(&stack_b);
	if (flag == 1)
		write (1, "sb\n", 1);
}

void	ss(t_list **stack_a, t_list **stack_b, int flag)
{
	swap(&stack_a);
	swap(&stack_b);
	if (flag == 1)
		write (1, "ss\n", 1);
}

//sa -> Swap the first 2 elements at the top of stack a.
//sb -> Swap the first 2 elements at the top of stack b.
//ss -> sa and sb at the same time.