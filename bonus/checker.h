/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:52:51 by tabadawi          #+#    #+#             */
/*   Updated: 2024/03/09 18:40:30 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap.h"
# include "get_next_line/get_next_line.h"

void	read_moves(t_list *stack_a, t_list *stack_b);
void	move_redirect(t_list *stack_a, t_list *stack_b, char *move);
int		ft_strcmp(char *s1, char *s2);
void	do_push(char *move, t_list *stack_a, t_list *stack_b);
void	do_swap(char *move, t_list *stack_a, t_list *stack_b);
void	do_rot(char *move, t_list *stack_a, t_list *stack_b);
void	do_revrot(char *move, t_list *stack_a, t_list *stack_b);

#endif