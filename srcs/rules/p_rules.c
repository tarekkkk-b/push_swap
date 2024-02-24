/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_rules.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:18:23 by tabadawi          #+#    #+#             */
/*   Updated: 2024/02/24 14:56:39 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	push(t_list	**stack1, t_list **stack2)
{
	t_list	*temp;

	temp = (*stack1);
	*stack1 = (*stack1)->next;
	ft_lstadd_front(stack2, ft_lstnew(temp->content));
	free (temp);
	// int		integer;
	// integer = (*stack1)->content;
	// temp = *stack1;
	// *stack1 = (*stack1)->next;
	// free (temp);
	// temp = ft_lstnew(integer);
	// ft_lstadd_front(stack2, temp);
}

void	pa(t_list **stack_a, t_list **stack_b, int flag)
{
	push(stack_b, stack_a);
	if (flag == 1)
		write (1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b, int flag)
{
	push(stack_a, stack_b);
	if (flag == 1)
		write (1, "pb\n", 3);
}

//pa -> Take the first element at the top of b and put it at the top of a.
		//Do nothing if b is empty.
//pb -> Take the first element at the top of a and put it at the top of b.
		//Do nothing if a is empty.
//have it toggable between print and no print