/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:25:44 by tabadawi          #+#    #+#             */
/*   Updated: 2025/01/13 14:07:37 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

	if (!av[1] || !av[1][0])
		exiting(NULL, NULL);
	i = 0;
	while (++i <= ac)
		if (ft_isspace(av[i]))
			exiting(NULL, NULL);
	input = ft_strdup(av[1]);
	i = 1;
	while (++i <= ac)
	{
		if (!av[i] || !av[i][0])
			exiting(input, NULL);
		input = ft_strjoin(input, av[i]);
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
