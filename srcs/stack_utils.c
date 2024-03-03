/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:15:55 by tabadawi          #+#    #+#             */
/*   Updated: 2024/03/03 21:25:50 by tabadawi         ###   ########.fr       */
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

int	findindex(int content, t_list **stack)
{
	int	i;
	t_list	*temp;
	t_list	*max;
	int	save;

	save = -1;
	i = 0;
	temp = (*stack);
	max = findmin(stack);
	while (temp)
	{
		if (temp->content >= max->content && content > temp->content)
		{
			max = temp;
			save = i;
		}
		temp = temp->next;
		i++;
	}
	if (save == -1)
		return (findmaxindex(stack));
	return (save);
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
