/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:25:03 by tabadawi          #+#    #+#             */
/*   Updated: 2024/02/04 18:32:49 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//###################################################//
//					libraries						//
//##################################################//

# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

//###################################################//
//					structs							//
//##################################################//

typedef struct s_split
{
	int		i;
	char	**split;
	int		wordcount;
}	t_split;

typedef struct s_input
{
	int		i;
	int		numbercount;
	char	*input;
	int		*intarr;
	char	**sp_inp;
}	t_input;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

//###################################################//
//					functions						//
//##################################################//

t_list	*ft_lstnew(void *content);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstlast(t_list *lst);
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void	*));
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
long	ft_atoi(const char *str, int *intarr, char **arr);
char	**ft_split(char const *s, char c);
char	**freeing(char **split);
char	*ft_strjoin(char *s1, char *s2);
char	*join_args(char *input, char **split, int count);
char	*ft_strdup(char *s1);
int		ft_lstsize(t_list *lst);
int		ft_isspace(char	*str);
int		ft_isdigit(int c);
int		ft_strlen(const char *str);
int		checker(int **intarr, int number, int count);
int		inputcount(const char *s, char c);
int		*input_handling(char **str, int count);
int		*parser(char **arr, int count);

#endif
