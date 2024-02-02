/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:25:31 by tabadawi          #+#    #+#             */
/*   Updated: 2024/02/01 20:35:13 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

size_t	_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = -1;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[++i] && (i < dstsize - 1))
		dst[i] = src[i];
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*_strdup(char *s1)
{
	char	*s2;

	s2 = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!s2)
		return (NULL);
	_strlcpy(s2, s1, ft_strlen(s1) + 1);
	return (s2);
}

char	**freeing(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free (split[i++]);
	free (split);
	return (NULL);
}

int	wordcount(const char *s, char c)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			x++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (x);
}
