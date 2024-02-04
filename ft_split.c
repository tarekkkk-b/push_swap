/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:34:49 by tabadawi          #+#    #+#             */
/*   Updated: 2024/02/04 18:34:57 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count(const char *input, char sep)
{
	int		wordcount;

	wordcount = 0;
	while (*input)
	{
		while (*input == sep)
			input++;
		while (*input != sep && *input)
		{
			input++;
			if (*input == sep || *input == '\0')
				wordcount++;
		}
	}
	return (wordcount);
}

static char	*word_alloc(const char *input, char sep)
{
	int		i;
	char	*word;

	i = 0;
	if (!input)
		return (NULL);
	while (input[i] != '\0' && input[i] != sep)
		i++;
	word = malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (input[i] != '\0' && input[i] != sep)
	{
		word[i] = input[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *input, char sep)
{
	t_split	var;

	var.i = 0;
	if (!input)
		return (NULL);
	var.wordcount = count(input, sep);
	var.split = malloc(sizeof(char *) * (var.wordcount + 1));
	if (!var.split)
		return (NULL);
	while (*input)
	{
		while (*input && *input == sep)
			input++;
		if (*input && *input != sep)
		{
			var.split[var.i] = word_alloc(input, sep);
			if (!(var.split[var.i]))
				return (freeing(var.split));
			var.i++;
			while (*input && *input != sep)
				input++;
		}
	}
	var.split[var.i] = (NULL);
	return (var.split);
}
