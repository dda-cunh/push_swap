/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:55:59 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/05/09 12:28:15 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	saob(t_stack **stack, char aob)
{
	int	tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = tmp;
	if (aob == 'a')
		ft_putstr_fd("sa\n", 1);
	if (aob == 'b')
		ft_putstr_fd("sb\n", 1);
}

void	paob(t_stack **to, t_stack **from, char aob)
{
	t_stack	*tostart;

	tostart = *to;
	*to = *from;
	*from = (*from)->next;
	(*to)->next = tostart;
	if (aob == 'a')
		ft_putstr_fd("pa\n", 1);
	if (aob == 'b')
		ft_putstr_fd("pb\n", 1);
}

void	raob(t_stack **stack, char aob)
{
	t_stack	*top;
	t_stack	*last;

	if (*stack && (*stack)->next)
	{
		top = (*stack);
		last = stlast((*stack));
		(*stack) = ((*stack))->next;
		top->next = NULL;
		last->next = top;
		if (aob == 'a')
			ft_putstr_fd("ra\n", 1);
		if (aob == 'b')
			ft_putstr_fd("rb\n", 1);
	}
}

void	rraob(t_stack **stack, char aob)
{
	t_stack	*top;
	t_stack	*last;
	t_stack	*prev_last;

	if (*stack && (*stack)->next)
	{
		top = (*stack);
		last = *(stack);
		while (last->next)
		{
			prev_last = last;
			last = last->next;
		}
		(*stack) = last;
		(*stack)->next = top;
		prev_last->next = NULL;
		if (aob == 'a')
			ft_putstr_fd("rra\n", 1);
		if (aob == 'b')
			ft_putstr_fd("rrb\n", 1);
	}
}

void	joint_op(t_stack **a, t_stack **b, char op)
{
	if (op == 'r')
	{	
		raob(a, '\0');
		raob(b, '\0');
		ft_putstr_fd("rr\n", 1);
	}
	if (op == 's')
	{
		saob(a, '\0');
		saob(b, '\0');
		ft_putstr_fd("ss\n", 1);
	}
	if (op == 't')
	{
		rraob(a, '\0');
		rraob(b, '\0');
		ft_putstr_fd("rrr\n", 1);
	}
}
