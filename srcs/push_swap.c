/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:24:42 by tabadawi          #+#    #+#             */
/*   Updated: 2024/03/04 21:54:39 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	indexer(t_list **stack)
{
	int		index;
	t_list	*temp;

	index = 0;
	temp = (*stack);
	while (temp)
	{
		temp->i = index++;
		temp = temp->next;
	}
}

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

static int largerindex(int index1, int index2)
{
	int larger;
	larger = 0;
	
	if (index1 > index2)
		larger = index1;
	else if (index2 > index1)
		larger = index2;
	return (larger);
}

static t_cheap	occ(t_list *node, t_list **stack1, t_list **stack2)
{
	t_cheap			info;
	unsigned int	temp;

	info.src = node;
	info.target = findtarget(node->content, stack2);
	info.cost = largerindex(info.src->i, info.target->i);
	info.flag = 1;
	temp = ft_lstsize((*stack2)) - info.target->i;
	if (temp < info.cost)
		info.cost = temp;
	info.flag = 1 + (temp < info.cost);
	temp = info.src->i + ft_lstsize((*stack2)) - info.target->i;
	if (temp < info.cost)
		info.cost = temp;
	info.flag = info.flag * !(temp < info.cost) + 3 * (temp < info.cost);
	temp = info.target->i + ft_lstsize((*stack1)) - info.src->i;
	if (temp < info.cost)
		info.cost = temp;
	info.flag = info.flag * !(temp < info.cost) + 4 * (temp < info.cost);
	printf("cost : %d    flag : %d\n", info.cost, info.flag);
	return (info);
}

static t_cheap	cheapestcalculater(t_list **stack1, t_list **stack2)
{
	t_list	*temp;
	t_cheap	cheapest;
	t_cheap	compare;

	temp = (*stack1);
	cheapest = occ(temp, stack1, stack2);
	while (temp)
	{
		compare = occ(temp, stack1, stack2);
		if (compare.cost < cheapest.cost)
			cheapest.cost = compare.cost;
		temp = temp->next;
	}
	return (cheapest);
}

int	main(int ac, char **av)
{
	int		*intarr;
	int		list_size;
	t_list	*stack_a;
	t_list	*stack_b = NULL;

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
	
	t_list	*temp = stack_a;
	printf("STACK A: ");
	while (temp)
	{
		printf ("%d ", temp->content);
		temp = temp->next;
	}
	while (ft_lstsize(stack_a) > 8)
		push(&stack_a, &stack_b);
	temp = stack_a;
	printf("\nSTACK B: ");
	printf("\n\n\nSTACK A: ");
	while (temp)
	{
		printf ("%d ", temp->content);
		temp = temp->next;
	}
	temp = stack_b;
	printf("\nSTACK B: ");
	while (temp)
	{
		printf ("%d ", temp->content);
		temp = temp->next;
	}
	printf("\n\n");
	temp = stack_a;
	
	t_cheap result = cheapestcalculater(&stack_a, &stack_b);
	printf("src %d and target %d and the cost is %d\n", result.src->content, result.target->content, result.cost);
	
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
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
