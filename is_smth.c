/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_smth.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:24:33 by tabadawi          #+#    #+#             */
/*   Updated: 2024/02/05 20:30:24 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace(char	*av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	ft_isdigit(int sp_inp)
{
	if (sp_inp >= '0' && sp_inp <= '9')
		return (1);
	return (0);
}
