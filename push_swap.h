/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:25:03 by tabadawi          #+#    #+#             */
/*   Updated: 2024/03/05 20:27:32 by tabadawi         ###   ########.fr       */
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
	int				content;
	int				i;
	struct s_list	*next;
}	t_list;

typedef struct s_cheap
{
	t_list				*src;
	t_list				*target;
	unsigned int		cost;
	int					flag;
}	t_cheap;

//###################################################//
//					functions						//
//##################################################//

//                 list functions                 //

t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void	*));
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);

//               libft functions               //

char	**ft_split(char const *input, char sep);
char	*ft_strjoin(char *input, char *argv);
char	*ft_strdup(char *argv);
long	ft_atoi(const char *sp_inp_i, int *intarr, char **sp_inp);
int		ft_isdigit(int sp_inp);
int		ft_isspace(char	*av);
int		ft_strlen(const char *str);

//               utils functions               //

char	**freeing(char **split);
char	*join_args(char *input, char **av, int ac);
int		*input_handling(char **av, int ac, int *i);
int		*parser(char **sp_inp, int numbercount, int *i2);
void	exiting(void *intarr, char **sp_inp);
int		checker(int *intarr, int number, int count);
int		inputcount(const char *input, char sep);

//               rules functions               //

void	push(t_list	**stack1, t_list **stack2);
void	pa(t_list **stack_a, t_list **stack_b, int flag);
void	pb(t_list **stack_a, t_list **stack_b, int flag);
void	swap(t_list **stack);
void	sa(t_list **stack_a, int flag);
void	sb(t_list **stack_b, int flag);
void	ss(t_list **stack_a, t_list **stack_b, int flag);
void	revrot(t_list **stack);
void	rra(t_list **stack_a, int flag);
void	rrb(t_list **stack_b, int flag);
void	rrr(t_list **stack_a, t_list **stack_b, int flag);
void	rot(t_list **stack);
void	ra(t_list **stack_a, int flag);
void	rb(t_list **stack_b, int flag);
void	rr(t_list **stack_a, t_list **stack_b, int flag);

//                 stack utils                //

int		stackissorted(t_list **stack);
void	sortthree(t_list **stack);
t_list	*findtarget(int content, t_list **stack);
t_list	*findtarget2(int content, t_list **stack);
t_list	*findmax(t_list **stack);
t_list	*findmin(t_list **stack);

#endif
