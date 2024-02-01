/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:25:16 by tabadawi          #+#    #+#             */
/*   Updated: 2024/02/01 21:03:13 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	words(const char *s, char c)
{
	int		wordcount;

	wordcount = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		while (*s != c && *s)
		{
			s++;
			if (*s == c || *s == '\0')
				wordcount++;
		}
	}
	return (wordcount);
}

static char	*wordsize(const char *s, char c)
{
	int		i;
	char	*word;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0' && s[i] != c)
		i++;
	word = malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	t_split	hey;

	hey.i = 0;
	if (!s)
		return (NULL);
	hey.wordcount = words(s, c);
	hey.split = malloc(sizeof(char *) * (hey.wordcount + 1));
	if (!hey.split)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			hey.split[hey.i] = wordsize(s, c);
			if (!(hey.split[hey.i]))
				return (freeer(hey.split));
			hey.i++;
			while (*s && *s != c)
				s++;
		}
	}
	hey.split[hey.i] = (NULL);
	return (hey.split);
}
