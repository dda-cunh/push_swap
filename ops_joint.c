/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_joint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:12:54 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/05/07 22:21:29 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	min_top(t_stack **a_head, t_stack **b_head)
{
	int		i;
	int		size;
	int		min_i;
	long	min;
	t_stack	*a;

	a = *a_head;
	if (a)
	{
		i = 0;
		min = a->value;
		min_i = 0;
		a = a->next;
		while (a)
		{
			i++;
			if (a->value < min)
			{
				min = a->value;
				min_i = i;
			}
			a = a->next;
		}
		size = currsize(*a_head);
		if (min_i > size / 2)
			while (min_i++ < size)
				rraob(a_head, '\0');
		else
			while (min_i--)
				raob(a_head, '\0');
		if (a_head && (*a_head)->next)
		{
			paob(b_head, a_head, '\0');
			min_top(a_head, b_head);
		}
	}
}

t_stack	*prevlast(t_stack *stack)
{
	t_stack	*last;
	t_stack	*prev_last;

	if (stack && stack->next)
	{
		last = stack;
		while (last->next)
		{
			prev_last = last;
			last = last->next;
		}
		return (prev_last);
	}
	return (NULL);
}

void	ss(t_stack **stack_a, t_stack **stack_b, int bonus)
{
	saob(stack_a, '\0');
	saob(stack_b, '\0');
	if (!bonus)
		ft_putstr_fd("ss\n", 1);
}

void	rr(t_stack **stack_a, t_stack **stack_b, int bonus)
{
	raob(stack_a, '\0');
	raob(stack_b, '\0');
	if (!bonus)
		ft_putstr_fd("rr\n", 1);
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int bonus)
{
	rraob(stack_a, '\0');
	rraob(stack_b, '\0');
	if (!bonus)
		ft_putstr_fd("rrr\n", 1);
}
