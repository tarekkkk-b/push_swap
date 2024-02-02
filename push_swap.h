/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:25:03 by tabadawi          #+#    #+#             */
/*   Updated: 2024/02/01 21:05:40 by tabadawi         ###   ########.fr       */
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

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int	    ft_lstsize(t_list *lst);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstlast(t_list *lst);
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void	*));
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
long	ft_atoi(const char *str, int *intarr, char **arr);
int		ft_isspace(char	*str);
int		ft_isdigit(int c);
char	*ft_strjoin(char *s1, char *s2);
int		hmm(char *str, int	*arr);
int		hmm2(int *intarr, char **str, int i);
int		*parser(char **arr, int count);
int		*input_handling(char **str, int count);
char	**ft_split(char const *s, char c);
int		ft_strlen(const char *str);
size_t	_strlcpy(char *dst, const char *src, size_t dstsize);
int		checker(int **intarr, int number, int count);
char	*joining(char *input, char **split, int count);
char	**freeing(char **split);
int		wordcount(const char *s, char c);
char	*_strdup(char *s1);

#endif
