/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 21:26:59 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/05/08 22:56:10 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_rot(t_stack *stack, int size)
{
	int		i;
	int		max[2];

	if (!stackisrsort(stack, size))
	{
		i = 0;
		max[1] = stack->value;
		max[0] = 0;
		stack = stack->next;
		while (stack)
		{
			i++;
			if (stack->value > max[1])
			{
				max[1] = stack->value;
				max[0] = i;
			}
			stack = stack->next;
		}
		if (max[0] > size / 2)
			return (max[0] - size);
		else
			return (max[0]);
	}
	return (0);
}

int	min_rot(t_stack *stack, int size)
{
	int		i;
	int		min[2];

	if (!stackissort(stack, size))
	{
		i = 0;
		min[1] = stack->value;
		min[0] = 0;
		stack = stack->next;
		while (stack)
		{
			i++;
			if (stack->value < min[1])
			{
				min[1] = stack->value;
				min[0] = i;
			}
			stack = stack->next;
		}
		if (min[0] > size / 2)
			return (min[0] - size);
		else
			return (min[0]);
	}
	return (0);
}

void	maxtoa(t_stack **a, t_stack **b)
{
	int	rot;

	while (*b)
	{
		rot = max_rot(*b, currsize(*b));
		if (rot < 0)
			while (rot++)
				rraob(b, 'b');
		else
			while (rot--)
				raob(b, 'b');
		paob(a, b, 'a');
	}
}

static t_stack	*init_c(t_stack *a)
{
	t_stack	*start;
	t_stack	*c;

	start = NULL;
	if (a)
	{
		c = stnew(a->value);
		start = c;
		a = a->next;
		while (a)
		{
			c->next = stnew(a->value);
			c = c->next;
			a = a->next;
		}
	}
	return (start);
}

int	get_mid(t_stack **a, int ac)
{
	int		i;
	int		mid;
	t_stack	*temp;
	t_stack	*c;
	t_stack	*d;

	c = init_c(*a);
	d = NULL;
	min_top(&c, &d);
	while (d)
		paob(&c, &d, '\0');
	i = 0;
	while (i++ <= (ac - 1) / 6)
	{
		temp = c;
		mid = (c->value);
		c = c->next;
		free(temp);
	}
	clear_stacks(c, d);
	return (mid);
}
