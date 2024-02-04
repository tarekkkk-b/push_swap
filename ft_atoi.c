/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:24:24 by tabadawi          #+#    #+#             */
/*   Updated: 2024/02/04 22:35:32 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	limitcheck(long result, int *intarr, char **arr)
{
	if (result > INT_MAX || result < INT_MIN)
	{
		free (intarr);
		freeing(arr);
		printf("Error\n");
		exit(1);
	}
}

static long	overflowcheck(const char *str, int *intarr, char **arr, int i)
{
	long	result;
	long	temp;

	result = 0;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		temp = result;
		result *= 10;
		result += str[i] - '0';
		if (result < temp)
		{
			free (intarr);
			freeing (arr);
			printf("Error\n");
			exit (1);
		}
		i++;
	}
	return (result);
}

long	ft_atoi(const char *str, int *intarr, char **arr)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	result = overflowcheck(str, intarr, arr, i);
	result = result * sign;
	return (limitcheck(result, intarr, arr), result);
}
