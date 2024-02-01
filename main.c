/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:24:42 by tabadawi          #+#    #+#             */
/*   Updated: 2024/02/01 21:13:27 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stackmaker(char **str, int count)
{
	t_stack	stack;

	stack.input = NULL;
	stack.input = joined(stack.input, str, count);
	stack.numbercount = wordcount(stack.input, ' ');
	stack.tarr = ft_split(stack.input, ' ');
	if (!stack.tarr)
	{
		free(stack.input);
		exit(printf("bad5\n"));
	}
	stack.i = 0;
	free(stack.input);
	if (!stack.tarr || stack.tarr[stack.i] == 0 || stack.tarr[stack.i] == NULL)
	{
		freeer(stack.tarr);
		exit(printf("bad2\n"));
	}
	stack.intarr = parser(stack.tarr, stack.numbercount);
	if (stack.intarr)
		printf("good\n");
	else
		exit(printf("bad3\n"));
	return (stack.intarr);
}

int	main(int ac, char **av)
{
	int	*intarr;

	if (ac < 2)
		exit(printf("bad1\n"));
	intarr = stackmaker(av, ac - 1);
	free (intarr);
	return (0);
}
