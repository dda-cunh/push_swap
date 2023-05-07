/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines_per_functionxd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:33:28 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/05/07 21:36:21 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dotop(t_stack **a, t_stack **b)
{
	while ((*a) && (*a)->value > stlast((*a))->value)
	{
		if ((*b) && (*b)->next && ((*b)->value < stlast(*b)->value))
			rr(a, b, 1);
		else
			raob(a, '\0');
	}
	while ((*b) && (*b)->value < stlast((*b))->value)
	{
		if ((*a)->next && ((*a)->value > stlast((*a))->value))
			rr(a, b, 1);
		else
			raob(b, '\0');
	}
}

void	btoaxd(t_stack **a, t_stack **b)
{
	if (b && *b)
	{
		while ((*b)->next)
		{
			dotop(a, b);
			if ((*b)->value > (*b)->next->value)
				paob(a, b, '\0');
			else
			{
				if (*a && (*a)->next && (*a)->value > (*a)->next->value)
					ss(a, b, 0);
				else
					saob(b, '\0');
			}
		}
	}
}

void	atobxd(t_stack **a, t_stack **b)
{
	if ((*a)->value < (*a)->next->value)
		paob(b, a, '\0');
	else
	{
		if (*b && (*b)->next && (*b)->value < (*b)->next->value)
			ss(a, b, 0);
		else
			saob(a, '\0');
	}
}
