/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:24:11 by tabadawi          #+#    #+#             */
/*   Updated: 2024/01/31 16:24:14 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s2 || !(*s2))
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!str)
		return (NULL);
	while (s1 && s1[i])
		str[j++] = s1[i++];
	str[j++] = ' ';
	i = 0;
	while (s2[i] && s2[i] != '\n')
		str[j++] = s2[i++];
	str[j] = '\0';
	if (s1)
		free (s1);
	return (str);
}
