/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:09:20 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/05/08 20:11:25 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

int			print_error(t_stack *stack_a, t_stack *stack_b);
int			stackisrsort(t_stack *stack, int size);
int			stackissort(t_stack *stack, int size);
int			get_mid(t_stack **stack_a, int ac);
int			sthasle(t_stack *stack, int value);
int			min_rot(t_stack *stack, int size);
int			max_rot(t_stack *stack, int size);
int			parser(int ac, char **av);
int			currsize(t_stack *stack);
void		print_stacks(t_stack *stack_a, t_stack *stack_b);
void		clear_stacks(t_stack *stack_a, t_stack *stack_b);
void		paob(t_stack **to, t_stack **from, char aob);
void		min_top(t_stack **a_head, t_stack **b_head);
void		joint_op(t_stack **a, t_stack **b, char op);
void		atob(t_stack **a, t_stack **b, int size);
void		btoa(t_stack **a, t_stack **b, int size);
void		dotop(t_stack **a, t_stack **b);
void		maxtoa(t_stack **a, t_stack **b);
void		rraob(t_stack **stack, char aob);
void		raob(t_stack **stack, char aob);
void		saob(t_stack **stack, char aob);
void		stclear(t_stack *st);
t_stack		*init_stack(int ac, char **av);
t_stack		*stlast(t_stack *st);
t_stack		*stnew(int value);

#endif