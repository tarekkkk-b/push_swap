/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:01:00 by tabadawi          #+#    #+#             */
/*   Updated: 2024/03/07 17:43:55 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	redirect(t_cheap info, t_list **stack1, t_list **stack2)
{
	if (info.flag == 1)
		rotbothup(info, stack1, stack2);
	if (info.flag == 2)
		rotbothdown(info, stack1, stack2);
	if (info.flag == 3)
		rotarevrotb(info, stack1, stack2);
	if (info.flag == 4)
		rotbrevrota(info, stack1, stack2);
}

void	rotbothup(t_cheap info, t_list **stack1, t_list **stack2)
{
	if (!stack1 || !stack2 || !info.src || !info.target)
		return ;
	while (info.src->i > 0 && info.target->i > 0)
	{
		if (!(*stack1) || !(*stack2))
			break ;
		rr(stack1, stack2, 1);
		info.src->i--;
		info.target->i--;
	}
	while (info.src->i > 0)
	{
		if (!(*stack1))
			break ;
		ra(stack1, 1);
		info.src->i--;
	}
	while (info.target->i > 0)
	{
		if (!(*stack2))
			break ;
		rb(stack2, 1);
		info.target->i--;
	}
}

void	rotbothdown(t_cheap info, t_list **stack1, t_list **stack2)
{
	if (!stack1 || !stack2)
		return ;
	while ((ft_lstsize(*stack1) - info.src->i) > 0
		&& (ft_lstsize(*stack2) - info.target->i) > 0)
	{
		rrr(stack1, stack2, 1);
		info.src->i++;
		info.target->i++;
	}
	while ((ft_lstsize(*stack1) - info.src->i) > 0)
	{
		if (!(*stack1))
			break ;
		rra(stack1, 1);
		info.src->i++;
	}
	while ((ft_lstsize(*stack2) - info.target->i) > 0)
	{
		if (!(*stack2))
			break ;
		rrb(stack2, 1);
		info.target->i++;
	}
}

void	rotarevrotb(t_cheap info ,t_list **stack1, t_list **stack2)
{
	if (!stack1 || !stack2)
		return ;
	while (info.src->i > 0)
	{
		if (!(*stack1))
			break ;
		ra(stack1, 1);
		info.src->i--;
	}
	while ((ft_lstsize(*stack2) - info.target->i) > 0)
	{
		if (!(*stack2))
			break ;
		rrb(stack2, 1);
		info.target->i++;
	}
}

void	rotbrevrota(t_cheap info, t_list **stack1, t_list **stack2)
{
	if (!stack1 || !stack2)
		return ;
	while (info.target->i > 0)
	{
		if (!(*stack2))
			break ;
		rb(stack2, 1);
		info.target->i--;
	}
	while ((ft_lstsize(*stack1) - info.src->i) > 0)
	{
		if (!(*stack1))
			break ;
		rra(stack1, 1);
		info.src->i++;
	}
}
