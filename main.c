/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:53:34 by tabadawi          #+#    #+#             */
/*   Updated: 2024/03/09 17:06:13 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		*intarr;
	int		list_size;
	t_list	*stack_a;
	t_list	*stack_b;

	list_size = 0;
	stack_a = NULL;
	if (ac < 2)
		exit(0);
	intarr = input_handling(av, ac - 1, &list_size);
	if (list_size == 1)
	{
		free (intarr);
		exit (0);
	}
	stack_a = stackmaker(intarr, list_size, stack_a);
	stack_b = NULL;
	if (stackissorted(&stack_a) == 1)
	{
		sort(&stack_a, &stack_b);
		while (stackissorted(&stack_a) == 1)
			rra(&stack_a, 1);
	}
	ft_lstclear(&stack_a, free);
	return (0);
}
