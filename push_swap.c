/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:24:42 by tabadawi          #+#    #+#             */
/*   Updated: 2024/02/24 14:48:41 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
//create rules functions
	//push, swap, rot and rev rot
	//freeing function for temp pointers used
	//realize patterns
//sort three

//20 feb
//time and space complexity look into