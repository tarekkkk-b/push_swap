/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:15:55 by tabadawi          #+#    #+#             */
/*   Updated: 2024/03/09 20:34:40 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stackissorted(t_list **stack)
{
	t_list	*iter;

	if (!stack || !(*stack))
		return (0);
	iter = (*stack);
	while (iter->next)
	{
		if (iter->content < iter->next->content)
			iter = iter->next;
		else
			return (1);
	}
	return (0);
}

t_list	*findmax(t_list **stack)
{
	t_list	*max;
	t_list	*temp;

	if (!stack || !(*stack))
		return (NULL);
	temp = (*stack);
	max = temp;
	while (temp)
	{
		if (temp->content > max->content)
			max = temp;
		temp = temp->next;
	}
	return (max);
}

t_list	*findmin(t_list **stack)
{
	t_list	*min;
	t_list	*temp;

	if (!stack || !(*stack))
		return (NULL);
	temp = (*stack);
	min = temp;
	while (temp)
	{
		if (temp->content < min->content)
			min = temp;
		temp = temp->next;
	}
	return (min);
}

t_list	*findtarget(int content, t_list **stack)
{
	t_list	*temp;
	t_list	*target;
	t_list	*min;

	if (!stack || !(*stack))
		return (NULL);
	min = findmin(stack);
	if (content < min->content)
		return (findmax(stack));
	temp = (*stack);
	target = findmin(stack);
	while (temp)
	{
		if (temp->content >= target->content && content > temp->content)
			target = temp;
		temp = temp->next;
	}
	return (target);
}

void	indexer(t_list **stack)
{
	int		index;
	t_list	*temp;

	if (!stack || !(*stack))
		return ;
	index = 0;
	temp = (*stack);
	while (temp)
	{
		temp->i = index++;
		temp = temp->next;
	}
}
