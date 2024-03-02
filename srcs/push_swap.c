/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:24:42 by tabadawi          #+#    #+#             */
/*   Updated: 2024/03/02 12:15:15 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/// @brief handles input
/// @param av arguments
/// @param ac arg number
/// @param list_size total numbers in list
/// @return int array
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
	return (free (intarr), node);
}

// static int	stackissorted(t_list **stack)
// {
// 	t_list *iter = (*stack);
// 	while ((iter)->next)
// 	{
// 		if (iter->content < iter->next->content)
// 			iter = iter->next;
// 		else
// 			return (1);
// 	}
// 	return (0);
// }

// static t_list	*findmax(t_list **stack)
// {
// 	t_list	*max;
// 	t_list	*temp;

// 	temp = (*stack);
// 	max = temp;
// 	while (temp)
// 	{
// 		if (temp->content > max->content)
// 			max = temp;
// 		temp = temp->next;
// 	}
// 	return (max);
// }

static t_list	*findmin(t_list **stack)
{
	t_list	*min;
	t_list	*temp = (*stack);
	min = temp;
	while (temp)
	{
		if (temp->content < min->content)
			min = temp;
		temp = temp->next;
	}
	return (min);
}

// static void	sortthree(t_list **stack)
// {
// 	t_list	*max;

// 	max = findmax(stack);
// 	if ((*stack)->content == max->content)
// 		ra(stack, 1);
// 	else if ((*stack)->next->content == max->content)
// 		rra(stack, 1);
// 	if (stackissorted(stack) == 1)
// 		sa(stack, 1);
// }

static int	findmaxindex(t_list **stack)
{
	t_list	*max;
	t_list	*temp;
	int	i;
	int	save;

	i = 0;
	save = 0;
	temp = (*stack);
	max = temp;
	while (temp)
	{
		if (temp->content > max->content)
		{
			max = temp;
			save = i;
		}
		i++;
		temp = temp->next;
	}
	return (save);
}

static int	findindex(int content, t_list **stack)
{
	int	i;
	t_list	*temp;
	t_list	*max;
	int	save;

	save = -1;
	i = 0;
	temp = (*stack);
	max = findmin(stack);
	while (temp)
	{
		if (temp->content >= max->content && content > temp->content)
		{
			max = temp;
			save = i;
		}
		temp = temp->next;
		i++;
	}
	if (save == -1)
		return (findmaxindex(stack));
	return (save);
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
	// push test

	// t_list	*temp = stack_a;
	// printf("STACK A: ");
	// while (temp)
	// {
	// 	printf ("%d ", temp->content);
	// 	temp = temp->next;
	// }
	// while (stack_a->next)
	// 	push(&stack_a, &stack_b);
	// temp = stack_a;
	// printf("\nSTACK B: ");
	// printf("\n\n\nSTACK A: ");
	// while (temp)
	// {
	// 	printf ("%d ", temp->content);
	// 	temp = temp->next;
	// }
	// temp = stack_b;
	// printf("\nSTACK B: ");
	// while (temp)
	// {
	// 	printf ("%d ", temp->content);
	// 	temp = temp->next;
	// }
	// printf("\n");

	// swap test

	// t_list	*temp = stack_a;
	// printf("BEFORE: ");
	// while (temp)
	// {
	// 	printf("%d ", temp->content);
	// 	temp = temp->next;
	// }
	// swap (&stack_a);
	// temp = stack_a;
	// printf("\n\nAFTER: ");
	// while (temp)
	// {
	// 	printf("%d ", temp->content);
	// 	temp = temp->next;
	// }
	// printf ("\n");

	//rev rot test

	// t_list	*temp = stack_a;
	// printf("BEFORE: ");
	// while (temp)
	// {
	// 	printf("%d ", temp->content);
	// 	temp = temp->next;
	// }
	// revrot (&stack_a);
	// temp = stack_a;
	// printf("\n\nAFTER: ");
	// while (temp)
	// {
	// 	printf("%d ", temp->content);
	// 	temp = temp->next;
	// }
	// printf ("\n");
	
	// ft_lstclear(&stack_a, free);

	//rot test

	// t_list	*temp = stack_a;
	// printf("BEFORE: ");
	// while (temp)
	// {
	// 	printf("%d ", temp->content);
	// 	temp = temp->next;
	// }
	// rot (&stack_a);
	// temp = stack_a;
	// printf("\n\nAFTER: ");
	// while (temp)
	// {
	// 	printf("%d ", temp->content);
	// 	temp = temp->next;
	// }
	// printf ("\n");

	//multi rule test

	// 	stack_b = NULL;
	// 	t_list *temp = stack_a;
	// 	printf("before\n\n");
	// 	printf("STACK A: ");
	// 	while (temp)
	// 	{
	// 		printf ("%d ", temp->content);
	// 		temp = temp->next;
	// 	}
	// 	printf("\nSTACK B: ");
	// 	printf("\n\nafter push\n\n");
	// 	while (ft_lstsize(`) > 3)
	// 		push(&stack_a, &stack_b);
	// 	temp = stack_a;
	// 	printf("STACK A: ");
	// 	while (temp)
	// 	{
	// 		printf ("%d ", temp->content);
	// 		temp = temp->next;
	// 	}
	// 	temp = stack_b;
	// 	printf("\nSTACK B: ");
	// 	while (temp)
	// 	{
	// 		printf ("%d ", temp->content);
	// 		temp = temp->next;
	// 	}
	// 	printf("\n\nafter swap\n\n");
	// 	swap(&stack_a);
	// 	swap(&stack_b);
	// 	temp = stack_a;
	// 	printf("STACK A: ");
	// 	while (temp)
	// 	{
	// 		printf ("%d ", temp->content);
	// 		temp = temp->next;
	// 	}
	// 	temp = stack_b;
	// 	printf("\nSTACK B: ");
	// 	while (temp)
	// 	{
	// 		printf ("%d ", temp->content);
	// 		temp = temp->next;
	// 	}
	// 	printf("\n");

	//is sorted ? test
	
	// if (stackissorted(&stack_a) == 1)
	// {
	// 	printf ("not sorted\n");
	// 	ft_lstclear(&stack_a, free);
	// 	exit (0);
	// }
	// else if ((stackissorted(&stack_a) == 0))
	// {
	// 	printf("sorted\n");
	// 	ft_lstclear(&stack_a, free);
	// 	exit (0);
	// }

	//max test

	// t_list *max = findmax(&stack_a);
	// printf("%d\n", max->content);
	// ft_lstclear(&max, free);

	//min test

	// t_list *min = findmin(&stack_a);
	// printf("%d\n", min->content);
	// ft_lstclear(&min, free);

	//sort three test

	// t_list	*temp = stack_a;
	// printf("STACK A: ");
	// while (temp)
	// {
	// 	printf ("%d ", temp->content);
	// 	temp = temp->next;
	// }
	// if (stackissorted(&stack_a) == 1)
	// 	sortthree(&stack_a);
	// temp = stack_a;
	// printf("\n\n\nSORTED STACK A: ");
	// while (temp)
	// {
	// 	printf ("%d ", temp->content);
	// 	temp = temp->next;
	// }

	//index finder test

	// t_list	*temp = stack_a;
	// printf("STACK A: ");
	// while (temp)
	// {
	// 	printf ("%d ", temp->content);
	// 	temp = temp->next;
	// }
	// printf("\nSTACK B: ");
	// while (ft_lstsize(stack_a) > 6)
	// 	push(&stack_a, &stack_b);
	// rot(&stack_b);
	// rot(&stack_b);
	// rot(&stack_b);
	// temp = stack_a;
	// printf("\n\n\nSTACK A: ");
	// while (temp)
	// {
	// 	printf ("\n%d and target from STACK B is at index %d\n", temp->content, findindex(temp->content, &stack_b));
	// 	temp = temp->next;
	// }
	// temp = stack_b;
	// printf("\nSTACK B: \n");
	// while (temp)
	// {
	// 	printf ("%d\n", temp->content);
	// 	temp = temp->next;
	// }
	// printf("\n");
	
	// ft_lstclear(&stack_a, free);
	// ft_lstclear(&stack_b, free);
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
//create rules functions
	//push, swap, rot and rev rot
	//freeing function for temp pointers used
	//realize patterns
//sort three

//20 feb
//time and space complexity look into