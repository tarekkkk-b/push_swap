/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:24:11 by tabadawi          #+#    #+#             */
/*   Updated: 2024/02/04 15:48:36 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char *input, char *argv)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!argv || !(*argv))
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(input) + ft_strlen(argv) + 2));
	if (!str)
		return (NULL);
	while (input && input[i])
		str[j++] = input[i++];
	str[j++] = ' ';
	i = 0;
	while (argv[i] && argv[i] != '\n')
		str[j++] = argv[i++];
	str[j] = '\0';
	if (input)
		free (input);
	return (str);
}
