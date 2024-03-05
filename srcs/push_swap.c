/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:24:42 by tabadawi          #+#    #+#             */
/*   Updated: 2024/03/05 22:01:41 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	indexer(t_list **stack)
{
	if (!stack || !(*stack))
		return ;
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

static int	largerindex(int index1, int index2)
{
	if (index1 >= index2)
		return (index1);
	return (index2);
}

static t_cheap	occ(t_list *node, t_list **stack1, t_list **stack2, int flag)
{
	t_cheap			info;
	unsigned int	temp;

	info.src = node;
	if (flag == 1)
		info.target = findtarget(node->content, stack2);
	if (flag == 2)
		info.target = findtarget2(node->content, stack2);
	//case 1
	info.cost = largerindex(info.src->i, info.target->i);
	info.flag = 1;

	//case 2
	temp = largerindex(ft_lstsize((*stack2)) - info.target->i,
			ft_lstsize((*stack1)) - info.src->i);
	info.flag = 1 + (temp < info.cost);
	if (temp < info.cost)
		info.cost = temp;

	//case 3
	temp = info.src->i + (ft_lstsize((*stack2)) - info.target->i);
	info.flag = info.flag * !(temp < info.cost) + 3 * (temp < info.cost);
	if (temp < info.cost)
		info.cost = temp;

	//case 4
	temp = info.target->i + (ft_lstsize((*stack1)) - info.src->i);
	info.flag = info.flag * !(temp < info.cost) + 4 * (temp < info.cost);
	if (temp < info.cost)
		info.cost = temp;
	return (info);
}

static void	rotbothup(t_cheap info, t_list **stack1, t_list **stack2)
{
	if (!stack1 || !stack2 || !info.src || !info.target)
		return ;
	while (info.src->i > 0 && info.target->i > 0)
	{
		if (!(*stack1) || !(*stack2))
			break ;
		rr(stack1, stack2, 1);
		info.src->i--;
		info.target->i--;
	}
	while (info.src->i > 0)
	{
		if (!(*stack1))
			break ;
		ra(stack1, 1);
		info.src->i--;
	}
	while (info.target->i > 0)
	{
		if (!(*stack2))
			break ;
		rb(stack2, 1);
		info.target->i--;
	}
}

static void	rotbothdown(t_cheap info, t_list **stack1, t_list **stack2)
{
	if (!stack1 || !stack2)
		return ;
	while ((ft_lstsize(*stack1) - info.src->i) > 0 && 
		(ft_lstsize(*stack2) - info.target->i) > 0)
	{
		rrr(stack1, stack2, 1);
		info.src->i++;
		info.target->i++;
	}
	while ((ft_lstsize(*stack1) - info.src->i) > 0)
	{
		if (!(*stack1))
			break ;
		rra(stack1, 1);
		info.src->i++;
	}
	while ((ft_lstsize(*stack2) - info.target->i) > 0)
	{
		if (!(*stack2))
			break ;
		rrb(stack2, 1);
		info.target->i++;
	}
}

static void	rotarevrotb(t_cheap info, t_list **stack1, t_list **stack2)
{
	if (!stack1 || !stack2)
		return ;
	while (info.src->i > 0)
	{
		if (!(*stack1))
			break ;
		ra(stack1, 1);
		info.src->i--;
	}
	while ((ft_lstsize(*stack2) - info.target->i) > 0)
	{
		if (!(*stack2))
			break ;
		rrb(stack2, 1);
		info.target->i++;
	}
}

static void	rotbrevrota(t_cheap info, t_list **stack1, t_list **stack2)
{
	if (!stack1 || !stack2)
		return ;
	while (info.target->i > 0)
	{
		if (!(*stack2))
			break ;
		rb(stack2, 1);
		info.target->i--;
	}
	while ((ft_lstsize(*stack1) - info.src->i) > 0)
	{
		if (!(*stack1))
			break ;
		rra(stack1, 1);
		info.src->i++;
	}
}

static void	redirect(t_cheap info, t_list **stack1, t_list **stack2)
{
	if (info.flag == 1)
		rotbothup(info, stack1, stack2);
	if (info.flag == 2)
		rotbothdown(info, stack1, stack2);
	if (info.flag == 3)
		rotarevrotb(info, stack1, stack2);
	if (info.flag == 4)
		rotbrevrota(info, stack1, stack2);
}

static t_cheap	cheapestcalculater(t_list **stack1, t_list **stack2, int flag)
{
	t_list	*temp;
	t_cheap	cheapest;
	t_cheap	compare;

	if (!stack1 || !(*stack1) || !stack2 || !(*stack2))
	{
		cheapest.cost = 0;
		cheapest.src = (*stack1);
		cheapest.target = (*stack2);
		cheapest.flag = 1;
		return (cheapest);	
	}
	temp = (*stack1);
	cheapest = occ(temp, stack1, stack2, flag);
	temp = temp->next;
	while (temp)
	{
		compare = occ(temp, stack1, stack2, flag);
		if (compare.cost < cheapest.cost)
			cheapest.cost = compare.cost;
		temp = temp->next;
	}
	return (cheapest);
}

// static void print(t_list **stack)
// {
// 	t_list *temp = (*stack);
// 	while (temp)
// 	{
// 		printf ("%d", temp->content);
// 		temp = temp->next;
// 	}
// 	printf("\n");
// 	temp = (*stack);
// 	while (temp)
// 	{
// 		printf ("%d", temp->i);
// 		temp = temp->next;
// 	}
// 	printf("\n");
// }
static void	sort(t_list **stack_a, t_list **stack_b)
{
	t_cheap	cheapest;
	
	while (ft_lstsize(*stack_a) > 3 && ft_lstsize(*stack_b) < 2)
		pb(stack_a, stack_b, 1);
	indexer(stack_a);
	indexer(stack_b);
	while (ft_lstsize(*stack_a) > 3)
	{
		cheapest = cheapestcalculater(stack_a, stack_b, 1);
		redirect(cheapest, stack_a, stack_b);
		pb(stack_a, stack_b, 1);
		indexer(stack_a);
		indexer(stack_b);
	}
	sortthree(stack_a);
	indexer(stack_a);
	// while (*stack_b)
	// {
	// 	cheapest = cheapestcalculater(stack_b, stack_a, 2);
	// 	redirect(cheapest, stack_b, stack_a);
	// 	pa(stack_a, stack_b, 1);
	// 	indexer(stack_a);
	// 	indexer(stack_b);
	// }
	ft_lstclear(stack_b, free);
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
	stack_b = NULL;
	sort(&stack_a, &stack_b);
	while (stackissorted(&stack_a) == 1)
		rra(&stack_a, 1);
	// t_list *temp = stack_a;
	// while (temp)
	// {
	// 	printf("%d ", temp->content);
	// 	temp = temp->next;
	// }
	// printf ("\n");
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
