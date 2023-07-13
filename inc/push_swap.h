/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:09:20 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/07/13 21:54:43 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				ideal_index;
	struct s_stack	*next;
}	t_stack;

/* ************************************************************************** */
/*                             stack_utils.c                                  */
/* ************************************************************************** */

int			currsize(t_stack *stack);
void		print_stacks(t_stack *stack_a, t_stack *stack_b);
void		stclear(t_stack *st);
t_stack		*stlast(t_stack *st);
t_stack		*stnew(int value);

/* ************************************************************************** */
/*                                sort.c                                      */
/* ************************************************************************** */
t_stack		*init_c(t_stack *a);
int			get_mid(t_stack *stack_a, int ac);
int			min_rot(t_stack *stack, int size);
int			max_rot(t_stack *stack, int size);
void		maxtoa(t_stack **a, t_stack **b, int fake);

/* ************************************************************************** */
/*                               utils.c                                      */
/* ************************************************************************** */
int			print_error(t_stack *stack_a, t_stack *stack_b);
int			stackisrsort(t_stack *stack, int size);
int			stackissort(t_stack *stack, int size);
int			sthasle(t_stack *stack, int value);
void		clear_stacks(t_stack *stack_a, t_stack *stack_b);

/* ************************************************************************** */
/*                               stack.c                                      */
/* ************************************************************************** */
int			parser(int ac, char **av);
void		mintob(t_stack **a, t_stack **b, int fake, int n);
t_stack		*init_stack(int ac, char **av);

/* ************************************************************************** */
/*                                ops.c                                       */
/* ************************************************************************** */
void		paob(t_stack **to, t_stack **from, char aob);
void		joint_op(t_stack **a, t_stack **b, char op);
void		rraob(t_stack **stack, char aob);
void		raob(t_stack **stack, char aob);
void		saob(t_stack **stack, char aob);

/* ************************************************************************** */
/*                              index_utils.c                                 */
/* ************************************************************************** */
void		get_ideal_i(t_stack **a);
void		print_ideal_i(t_stack *a);

#endif