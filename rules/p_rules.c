/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_rules.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:18:23 by tabadawi          #+#    #+#             */
/*   Updated: 2024/03/09 19:24:30 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_list	**stack1, t_list **stack2)
{
	t_list	*temp;

	if (!*stack1)
		return ;
	temp = (*stack1);
	*stack1 = (*stack1)->next;
	ft_lstadd_front(stack2, ft_lstnew(temp->content));
	t_list *itr;

	itr = (*stack2);
	while (itr)
	{
		printf("stack 2 node is: %d\n", itr->content);
		itr= itr->next;
	}
	itr = (*stack1);
	while (itr)
	{
		printf("stack 1 node is: %d\n", itr->content);
		itr= itr->next;
	}
	printf("thats it\n");
	free (temp);
}

void	pa(t_list **stack_a, t_list **stack_b, int flag)
{
	if (!stack_b || !(*stack_b))
		return ;
	push(stack_b, stack_a);
	if (flag == 1)
		write (1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b, int flag)
{
	if (!stack_a || !(*stack_a))
		return ;
	push(stack_a, stack_b);
	if (flag == 1)
		write (1, "pb\n", 3);
}
