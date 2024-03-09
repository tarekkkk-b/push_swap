/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_rules.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:09:24 by tabadawi          #+#    #+#             */
/*   Updated: 2024/03/09 17:05:14 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_list **stack)
{
	int	tmp;

	tmp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp;
}

void	sa(t_list **stack_a, int flag)
{
	if (!stack_a || !(*stack_a))
		return ;
	swap(stack_a);
	if (flag == 1)
		write (1, "sa\n", 3);
}

void	sb(t_list **stack_b, int flag)
{
	if (!stack_b || !(*stack_b))
		return ;
	swap(stack_b);
	if (flag == 1)
		write (1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b, int flag)
{
	if (stack_a && (*stack_a))
		swap(stack_a);
	if (stack_b && (*stack_b))
		swap(stack_b);
	if (flag == 1)
		write (1, "ss\n", 4);
}
