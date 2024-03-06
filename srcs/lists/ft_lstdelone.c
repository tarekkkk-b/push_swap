/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:44:16 by tabadawi          #+#    #+#             */
/*   Updated: 2024/03/06 20:30:10 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	(void)del;
	if (del != NULL)
	{
		if (lst)
		{
			free(lst);
		}
	}
}
