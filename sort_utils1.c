/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:50:34 by tabadawi          #+#    #+#             */
/*   Updated: 2024/03/09 17:06:18 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sortthree(t_list **stack)
{
	t_list	*max;

	if (!stack || !(*stack) || ft_lstsize(*stack) != 3)
		return ;
	max = findmax(stack);
	if ((*stack)->content == max->content)
		ra(stack, 1);
	else if ((*stack)->next->content == max->content)
		rra(stack, 1);
	if (stackissorted(stack) == 1)
		sa(stack, 1);
}

static t_cheap	replace(t_cheap cheapest, t_cheap compare)
{
	cheapest.cost = compare.cost;
	cheapest.flag = compare.flag;
	cheapest.src = compare.src;
	cheapest.target = compare.target;
	return (cheapest);
}

t_cheap	occ(t_list *node, t_list **stack1, t_list **stack2)
{
	t_cheap			info;
	unsigned int	temp;

	info.src = node;
	info.target = findtarget(node->content, stack2);
	info.cost = largerindex(info.src->i, info.target->i);
	info.flag = 1;
	temp = largerindex(ft_lstsize((*stack2)) - info.target->i,
			ft_lstsize((*stack1)) - info.src->i);
	info.flag = 1 + (temp < info.cost);
	if (temp < info.cost)
		info.cost = temp;
	temp = info.src->i + (ft_lstsize((*stack2)) - info.target->i);
	info.flag = info.flag * !(temp < info.cost) + 3 * (temp < info.cost);
	if (temp < info.cost)
		info.cost = temp;
	temp = info.target->i + (ft_lstsize((*stack1)) - info.src->i);
	info.flag = info.flag * !(temp < info.cost) + 4 * (temp < info.cost);
	if (temp < info.cost)
		info.cost = temp;
	return (info);
}

t_cheap	cheapestcalculater(t_list **stack1, t_list **stack2)
{
	t_list	*temp;
	t_cheap	cheapest;
	t_cheap	compare;

	if (!stack1 || !(*stack1) || !stack2 || !(*stack2))
	{
		cheapest.cost = 0;
		cheapest.src = (*stack1);
		cheapest.target = (*stack2);
		cheapest.flag = 1;
		return (cheapest);
	}
	temp = (*stack1);
	cheapest = occ(temp, stack1, stack2);
	temp = temp->next;
	while (temp)
	{
		compare = occ(temp, stack1, stack2);
		if (compare.cost < cheapest.cost)
			cheapest = replace(cheapest, compare);
		temp = temp->next;
	}
	return (cheapest);
}

int	largerindex(int index1, int index2)
{
	if (index1 >= index2)
		return (index1);
	return (index2);
}
