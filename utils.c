/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:25:31 by tabadawi          #+#    #+#             */
/*   Updated: 2024/01/31 16:25:33 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	_strlen(const char *str)
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
		return (_strlen(src));
	while (src[++i] && (i < dstsize - 1))
		dst[i] = src[i];
	dst[i] = '\0';
	return (_strlen(src));
}

char	*_strdup(char *s1)
{
	char	*s2;

	s2 = malloc(sizeof(char) * (_strlen(s1) + 1));
	if (!s2)
		return (NULL);
	_strlcpy(s2, s1, _strlen(s1) + 1);
	return (s2);
}

char	**freeer(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
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
