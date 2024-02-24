/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:25:44 by tabadawi          #+#    #+#             */
/*   Updated: 2024/02/24 14:52:41 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checker(int *intarr, int number, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (number == intarr[i])
			return (1);
		else
			i++;
	}
	return (0);
}

char	*join_args(char *input, char **av, int ac)
{
	int	i;

	i = 1;
	if (av[i][0] == 0 || av[i] == NULL)
		exiting(NULL, NULL);
	while (i <= ac)
	{
		if (ft_isspace(av[i]) == 1)
			exiting(NULL, NULL);
		i++;
	}
	i = 1;
	input = ft_strdup(av[i++]);
	while (i <= ac)
	{
		if (av[i][0] == 0 || av[i] == NULL)
			exiting(input, NULL);
		input = ft_strjoin(input, av[i]);
		i++;
	}
	return (input);
}

void	exiting(void *intarr, char **sp_inp)
{
	if (intarr)
		free (intarr);
	if (sp_inp)
		freeing(sp_inp);
	write (2, "Error\n", 6);
	exit(1);
}
