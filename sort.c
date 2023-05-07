/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 21:26:59 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/05/07 22:48:02 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// void	both_top(t_stack **a, t_stack **b, int size)
// {
	
// }

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
	t_stack	*c;
	t_stack	*d;
	t_stack	*temp;
	int		mid;
	int		i;

	c = init_c(*a);
	d = NULL;
	min_top(&c, &d);
	btoa(&c, &d, ac - 1);
	i = 0;
	while (i++ <= (ac - 1) / 2)
	{
		temp = c;
		mid = (c->value);
		c = c->next;
		free(temp);
	}
	clear_stacks(c, d);
	return (mid);
}
