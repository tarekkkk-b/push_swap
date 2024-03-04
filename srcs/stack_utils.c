/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:15:55 by tabadawi          #+#    #+#             */
/*   Updated: 2024/03/04 10:34:09 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stackissorted(t_list **stack)
{
	t_list *iter = (*stack);
	while ((iter)->next)
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
	t_list	*temp = (*stack);
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

int	findmaxindex(t_list **stack)
{
	t_list	*max;
	t_list	*temp;
	int	i;
	int	save;

	i = 0;
	save = 0;
	temp = (*stack);
	max = temp;
	while (temp)
	{
		if (temp->content > max->content)
		{
			max = temp;
			save = i;
		}
		i++;
		temp = temp->next;
	}
	return (save);
}
