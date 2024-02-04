/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:25:31 by tabadawi          #+#    #+#             */
/*   Updated: 2024/02/04 17:23:25 by tabadawi         ###   ########.fr       */
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

static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
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

char	*ft_strdup(char *argv)
{
	char	*input;

	input = malloc(sizeof(char) * (ft_strlen(argv) + 1));
	if (!input)
		return (NULL);
	ft_strlcpy(input, argv, ft_strlen(argv) + 1);
	return (input);
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

int	inputcount(const char *input, char sep)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (input[i])
	{
		while (input[i] == sep)
			i++;
		if (input[i])
			x++;
		while (input[i] && input[i] != sep)
			i++;
	}
	return (x);
}
