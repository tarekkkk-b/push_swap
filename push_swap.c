/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:24:42 by tabadawi          #+#    #+#             */
/*   Updated: 2024/02/04 17:42:04 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*input_handling(char **av, int ac)
{
	t_input	var;

	var.input = NULL;
	var.input = join_args(var.input, av, ac);
	var.numbercount = inputcount(var.input, ' ');
	var.sp_inp = ft_split(var.input, ' ');
	if (!var.sp_inp)
	{
		free (var.input);
		exit(1);
	}
	var.i = 0;
	free (var.input);
	if (!var.sp_inp || var.sp_inp[var.i] == 0 || var.sp_inp[var.i] == NULL)
	{
		freeing(var.sp_inp);
		exit(1);
	}
	var.intarr = parser(var.sp_inp, var.numbercount);
	if (var.intarr)
		printf("good\n");
	else
		exit(1);
	return (var.intarr);
}

int	main(int ac, char **av)
{
	int	*intarr;

	if (ac < 2)
		exit(0);
	intarr = input_handling(av, ac - 1);
	free (intarr);
	return (0);
}
