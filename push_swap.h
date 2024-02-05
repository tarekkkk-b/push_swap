/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:25:03 by tabadawi          #+#    #+#             */
/*   Updated: 2024/02/05 20:31:59 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//###################################################//
//					libraries						//
//##################################################//

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
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
void	exiting(void *intarr, char **sp_inp);
long	ft_atoi(const char *sp_inp_i, int *intarr, char **sp_inp);
char	**ft_split(char const *input, char sep);
char	**freeing(char **split);
char	*ft_strjoin(char *input, char *argv);
char	*join_args(char *input, char **av, int ac);
char	*ft_strdup(char *argv);
int		ft_lstsize(t_list *lst);
int		ft_isspace(char	*av);
int		ft_isdigit(int sp_inp);
int		ft_strlen(const char *str);
int		checker(int *intarr, int number, int count);
int		inputcount(const char *input, char sep);
int		*input_handling(char **av, int ac);
int		*parser(char **sp_inp, int numbercount);

#endif
