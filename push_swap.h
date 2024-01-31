/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:25:03 by tabadawi          #+#    #+#             */
/*   Updated: 2024/01/31 16:25:07 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_split
{
	int		i;
	char	**split;
	int		wordcount;
}	t_split;

typedef struct s_stacker
{
	int		i;
	int		numbercount;
	char	*input;
	int		*intarr;
	char	**tarr;
}	t_stack;

void	limitcheck(long result);
long	t_atoi(const char *str);
int		ft_isspace(char	*str);
int		ft_isdigit(int c);
char	*strjoin(char *s1, char *s2);
int		hmm(char *str, int	*arr);
int		hmm2(int *intarr, char **str, int i);
int		*parser(char **arr, int count);
int		*stackmaker(char **str, int count);
char	**ft_split(char const *s, char c);
int		_strlen(const char *str);
size_t	_strlcpy(char *dst, const char *src, size_t dstsize);
int		checker(int **intarr, int number, int count);
char	*joined(char *input, char **split, int count);
char	**freeer(char **split);
int		wordcount(const char *s, char c);
char	*_strdup(char *s1);

#endif
