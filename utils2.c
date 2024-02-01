/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:25:44 by tabadawi          #+#    #+#             */
/*   Updated: 2024/02/01 21:10:41 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checker(int **intarr, int number, int count)
{
	int	i;
	int	*current;

	i = 0;
	current = *intarr;
	while (i < (int) count)
	{
		if (number == current[i])
			return (1);
		else
			i++;
	}
	return (0);
}

char	*joined(char *input, char **split, int count)
{
	int	i;

	i = 1;
	if (split[i][0] == 0 || split[i] == NULL)
		exit (printf("bad6\n"));
	while (i <= count)
	{
		if (ft_isspace(split[i]) == 1)
			exit(printf("bad7\n"));
		i++;
	}
	i = 1;
	input = _strdup(split[i++]);
	while (i <= count)
	{
		if (split[i][0] == 0 || split[i] == NULL)
		{
			free (input);
			exit (printf("bad8\n"));
		}
		input = strjoin(input, split[i]);
		i++;
	}
	return (input);
}
