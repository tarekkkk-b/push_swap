/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:43:28 by tabadawi          #+#    #+#             */
/*   Updated: 2024/03/09 17:03:29 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lastone;

	if (lst)
	{
		if (*lst)
		{
			lastone = ft_lstlast(*lst);
			lastone->next = new;
		}
		else
			*lst = new;
	}
}
