/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimized.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:25:48 by tabadawi          #+#    #+#             */
/*   Updated: 2024/01/29 21:35:20 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

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

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
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

char	*_strdup(const char *s1)
{
	char	*s2;

	s2 = malloc(sizeof(char) * (_strlen(s1) + 1));
	if (!s2)
		return (NULL);
	_strlcpy(s2, s1, _strlen(s1) + 1);
	return (s2);
}

void	limitcheck(long result)
{
	if (result > INT_MAX || result < INT_MIN)
		exit(printf("bad"));
}

long	t_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	result = result * sign;
	limitcheck(result);
	return (result);
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

char	*strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s2 || !(*s2))
		return (NULL);
	str = malloc(sizeof(char) * (_strlen(s1) + _strlen(s2) + 2));
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
		free(s1);
	return (str);
}

int	checker(int **intarr, int number, int count)
{
	int	i;
	int	*current;

	i = 0;
	current = *intarr;
	while (i < (int) count)
	{
		if (number == current[i])
			return (1);
		else
			i++;
	}
	return (0);
}

char	*joined(char *input, char **split, int count)
{
	int	i;

	i = 1;
	if (split[i][0] == 0 || split[i] == NULL)
		exit (printf("bad\n"));
	input = _strdup(split[i++]);
	while (i <= count)
	{
		if (split[i][0] == 0 || split[i] == NULL)
			exit (printf("bad\n"));
		input = strjoin(input, split[i]);
		i++;
	}
	return (input);
}

int	hmm(char *str, int	*arr)
{
	int	j;

	j = 0;
	if (str[j] == '-' || str[j] == '+')
		j++;
	if (str[j] == '\0')
		return (free(arr), 1);
	while (str[j])
	{
		if (ft_isdigit(str[j]) == 0)
			return (free(arr), 1);
		else
			j++;
	}
	return (0);
}

int	hmm2(int *intarr, char **str, int i)
{
	if (i == 0)
		intarr[i] = t_atoi(str[i]);
	else
	{
		if (checker(&intarr, t_atoi(str[i]), i) == 0)
			intarr[i] = t_atoi(str[i]);
		else
			return (1);
	}
	return (0);
}

int	parser(char **arr, int count)
{
	int	i;
	int	*intarr;

	i = 0;
	intarr = malloc(sizeof(int) * count);
	if (!intarr)
		return (1);
	while (i < count)
	{
		if (hmm(arr[i], intarr) == 0)
		{
			if (hmm2(intarr, arr, i) == 1)
				return (1);
		}
		else
			return (1);
		i++;
	}
	return (0);
}

void	stackmaker(char **str, int count)
{
	int		i;
	int		numbercount;
	char	*input;
	char	**tarr;

	input = NULL;
	input = joined(input, str, count);
	numbercount = wordcount(input, ' ');
	tarr = ft_split(input, ' ');
	i = 0;
	if (!tarr || tarr[i] == 0 || tarr[i] == NULL)
		exit (printf("bad\n"));
	free(input);
	if (parser(tarr, numbercount) == 0)
		printf("good");
	else
		exit(printf("bad\n"));
}

int	main(int ac, char **av)
{
	if (ac < 2)
		exit (printf("bad\n"));
	stackmaker(av, ac - 1);
	return (0);
}
