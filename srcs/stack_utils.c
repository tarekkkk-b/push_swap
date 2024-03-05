/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:15:55 by tabadawi          #+#    #+#             */
/*   Updated: 2024/03/05 21:01:29 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stackissorted(t_list **stack)
{
	if (!stack || !(*stack))
		return (0);
	t_list	*iter;

	iter = (*stack);
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
	if (!stack || !(*stack))
		return (NULL);
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
	if (!stack || !(*stack))
		return (NULL);
	t_list	*min;
	t_list	*temp;

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
	if (!stack || !(*stack))
		return (NULL);
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

t_list	*findtarget2(int content, t_list **stack)
{
	if (!stack || !(*stack))
		return (NULL);
	t_list	*temp;
	t_list	*target;
	t_list	*max;

	max = findmax(stack);
	if (content > max->content)
	{
		// printf("src : %d  and the target is : %d\n", content, findmin(stack)->content);
		return (findmin(stack));
	}
	temp = (*stack);
	target = findmax(stack);
	while (temp)
	{
		if (temp->content <= target->content && content < temp->content)
			target = temp;
		temp = temp->next;
	}
	// printf("src : %d  and the target is : %d\n", content, target->content);
	return (target);
}

void	sortthree(t_list **stack)
{
	if (!stack || !(*stack))
		return ;
	t_list	*max;

	max = findmax(stack);
	if ((*stack)->content == max->content)
		ra(stack, 1);
	else if ((*stack)->next->content == max->content)
		rra(stack, 1);
	if (stackissorted(stack) == 1)
		sa(stack, 1);
}
