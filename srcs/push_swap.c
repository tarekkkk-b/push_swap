/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:24:42 by tabadawi          #+#    #+#             */
/*   Updated: 2024/03/07 18:02:44 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*input_handling(char **av, int ac, int *list_size)
{
	t_input	var;

	var.input = NULL;
	var.input = join_args(var.input, av, ac);
	var.numbercount = inputcount(var.input, ' ');
	var.sp_inp = ft_split(var.input, ' ');
	if (!var.sp_inp)
		exiting(var.input, NULL);
	var.i = 0;
	free (var.input);
	if (!var.sp_inp || var.sp_inp[var.i] == 0 || var.sp_inp[var.i] == NULL)
		exiting(NULL, var.sp_inp);
	var.intarr = parser(var.sp_inp, var.numbercount, list_size);
	if (!var.intarr)
		exiting(NULL, NULL);
	return (var.intarr);
}

static t_list	*stackmaker(int *intarr, int list_size, t_list *node)
{
	int		i;
	t_list	*new;

	i = 0;
	while (i < list_size)
	{
		new = ft_lstnew(intarr[i]);
		if (!new)
		{
			ft_lstclear(&node, free);
			free (intarr);
			write (2, "Error\n", 6);
			exit(1);
		}
		ft_lstadd_back(&node, new);
		i++;
	}
	indexer(&node);
	return (free (intarr), node);
}

// static void print(t_list **stack)
// {
// 	t_list *temp = (*stack);
// 	while (temp)
// 	{
// 		printf ("%d\n", temp->content);
// 		temp = temp->next;
// 	}
// 	printf("\n");
// 	// temp = (*stack);
// 	// while (temp)
// 	// {
// 	// 	printf ("%d", temp->i);
// 	// 	temp = temp->next;
// 	// }
// 	// printf("\n");
// }

static void	pushback(t_list **stack_a, t_list **stack_b)
{
	if (!stack_b || !(*stack_b))
		return ;
	while (findmax(stack_b)->i != 0 && findmax(stack_b)->i > (ft_lstsize(*stack_b) / 2))
	{
		rrb(stack_b, 1);
		indexer(stack_b);
	}
	while(findmax(stack_b)->i != 0 && findmax(stack_b)->i <= (ft_lstsize(*stack_b) / 2))
	{
		rb(stack_b, 1);
		indexer(stack_b);
	}
	if((*stack_a)->content < (*stack_b)->content)
	{
		while (ft_lstlast(*stack_a)->content > (*stack_b)->content)
			rra(stack_a, 1);
	}
	while (*stack_b)
	{
		pa(stack_a, stack_b, 1);
		while ((*stack_b) && ft_lstlast(*stack_a)->content > (*stack_b)->content
			&& ft_lstlast(*stack_a)->content < (*stack_a)->content)
				rra(stack_a, 1);
	}
}

static void	sort(t_list **stack_a, t_list **stack_b)
{
	// while (ft_lstsize((*stack_a)) > 3 && ft_lstsize((*stack_b)) < 2)
	// 	pb(stack_a, stack_b, 1);
	// indexer(stack_a);
	// indexer(stack_b);
	// (void)pushback;
	while (ft_lstsize((*stack_a)) > 3)
	{
		redirect(cheapestcalculater(stack_a, stack_b), stack_a, stack_b);
		pb(stack_a, stack_b, 1);
		indexer(stack_a);
		indexer(stack_b);
	}
	sortthree(stack_a);
	indexer(stack_a);
	pushback(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	int		*intarr;
	int		list_size;
	t_list	*stack_a;
	t_list	*stack_b;

	list_size = 0;
	stack_a = NULL;
	if (ac < 2)
		exit(0);
	intarr = input_handling(av, ac - 1, &list_size);
	if (list_size == 1)
	{
		free (intarr);
		exit (0);
	}
	stack_a = stackmaker(intarr, list_size, stack_a);
	// printf("%d \n", list_size);
	stack_b = NULL;
	// check if sorted.
	sort(&stack_a, &stack_b);
	while (stackissorted(&stack_a) == 1)
		rra(&stack_a, 1);
	// print(&stack_a);
	// ft_lstclear(&stack_b, free);
	ft_lstclear(&stack_a, free);
	return (0);
}

///18 feb
// need to create a list struct
	// includes int num, next pointer
	// create a struct that has the head and tail pointer
// create a function that adds every int to the list(stack)
	// iterates the intarr and takes each element and puts it in its respective node
	// uses linked lists function to create nodes
// free intarr in the new function
// return to main

///19feb
// create rules functions
	// push, swap, rot and rev rot
	// freeing function for temp pointers used
	//r ealize patterns
// sort three

//20 feb
// time and space complexity look into

//3 march
// lots of updates
	// rules created
	// find max and min created
	// sort three created
	// i now store the index in the struct of the node
	// i also find the target node
	// i save the info in a new struct
		// basically saves
			// src, src index, target, and target index
// next step would be calculating the cost for each node and going for the cheapest
	// set the cheapest as the first info then iterate through stack to compare
	// soon as we find a cheaper move we set it as cheapest
	// execute then recalculate and comapare
// we will be sorting stack_b as we go this way, but to push back we need to do this process in reverse
// i believe nodeindex is no longer needed, keep it incase.

//4 march
// cheap stack was reduced to only having the src and target nodes
	// reason is now the nodes themselves are indexed
	// this eleminates the need of the functions "nodeindex" and "nodeatindex"
	// also findmaxindex is no longer needed
	// "findindex" modified to "findtarget" (more accurate)
