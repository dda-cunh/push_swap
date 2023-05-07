/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:09:20 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/05/07 22:18:36 by dda-cunh         ###   ########.fr       */
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

t_stack		*prevlast(t_stack *stack);
t_stack		*remove_top(t_stack *stack);
t_stack		*init_stack(int ac, char **av);
t_stack		*stlast(t_stack *st);
t_stack		*stnew(int value);
void		print_stacks(t_stack *stack_a, t_stack *stack_b);
void		raob(t_stack **stack, char aob);
void		rraob(t_stack **stack, char aob);
void		paob(t_stack **to, t_stack **from, char aob);
void		saob(t_stack **stack, char aob);
void		ss(t_stack **stack_a, t_stack **stack_b, int bonus);
void		rr(t_stack **stack_a, t_stack **stack_b, int bonus);
void		rrr(t_stack **stack_a, t_stack **stack_b, int bonus);
void		stadd_front(t_stack **st, t_stack *_new);
void		stadd_back(t_stack **st, t_stack *_new);
void		stclear(t_stack *st);
void		delvalue(int *value);
void		clear_stacks(t_stack *stack_a, t_stack *stack_b);
int			get_mid(t_stack **stack_a, int ac);
int			both_top(t_stack **a, t_stack **b, int size);
void		push_mid(t_stack **a, t_stack **b, int size, int mid);
void		dotop(t_stack **a, t_stack **b);
void		btoa(t_stack **a, t_stack **b, int size);
void		btoaxd(t_stack **a, t_stack **b);
void		atobxd(t_stack **a, t_stack **b);
void		a_logic(t_stack **a, t_stack **b);
void		min_top(t_stack **a_head, t_stack **b_head);
int			atob(t_stack **a, t_stack **b, int size);
int			stackissort(t_stack *stack, int size);
int			stackisrsort(t_stack *stack, int size);
int			print_error(t_stack *stack_a, t_stack *stack_b);
int			parser(int ac, char **av);
int			currsize(t_stack *stack);

#endif