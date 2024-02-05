/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:25:44 by tabadawi          #+#    #+#             */
/*   Updated: 2024/02/05 18:42:02 by tabadawi         ###   ########.fr       */
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
		exit (1);
	while (i <= ac)
	{
		if (ft_isspace(av[i]) == 1)
			exit(1);
		i++;
	}
	i = 1;
	input = ft_strdup(av[i++]);
	while (i <= ac)
	{
		if (av[i][0] == 0 || av[i] == NULL)
		{
			free (input);
			exit(1);
		}
		input = ft_strjoin(input, av[i]);
		i++;
	}
	return (input);
}
