/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:24:54 by tabadawi          #+#    #+#             */
/*   Updated: 2024/02/01 21:06:26 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	hmm(char *str, int	*arr)
{
	int	j;

	j = 0;
	if (str[j] == '-' || str[j] == '+')
		j++;
	if (str[j] == '\0')
		return (free (arr), 1);
	while (str[j])
	{
		if (ft_isdigit(str[j]) == 0)
			return (free (arr), 1);
		else
			j++;
	}
	return (0);
}

int	hmm2(int *intarr, char **str, int i)
{
	if (i == 0)
		intarr[i] = ft_atoi(str[i], intarr, str);
	else
	{
		if (checker(&intarr, ft_atoi(str[i], intarr, str), i) == 0)
			intarr[i] = ft_atoi(str[i], intarr, str);
		else
			return (free (intarr), 1);
	}
	return (0);
}

int	*parser(char **arr, int count)
{
	int	i;
	int	*intarr;

	i = 0;
	intarr = malloc(sizeof(int) * count);
	if (!intarr)
		return (freeing(arr), NULL);
	while (i < count)
	{
		if (hmm(arr[i], intarr) == 0)
		{
			if (hmm2(intarr, arr, i) == 1)
				return (freeing(arr), NULL);
		}
		else
			return (freeing(arr), NULL);
		i++;
	}
	freeing(arr);
	return (intarr);
}
