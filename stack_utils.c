/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:12:42 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/05/05 14:31:35 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stadd_front(t_stack **st, t_stack *new)
{
	if (st && new)
	{
		new->next = *st;
		*st = new;
	}
}

void	stclear(t_stack *st)
{
	t_stack	*next;

	while (st)
	{
		next = st->next;
		free(st);
		st = next;
	}
}

t_stack	*stnew(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

t_stack	*stlast(t_stack *st)
{
	if (!st)
		return (NULL);
	while (st->next)
		st = st->next;
	return (st);
}

void	stadd_back(t_stack **st, t_stack *new)
{
	t_stack	*last;

	if (st)
	{
		if (!*st)
			*st = new;
		else
		{
			last = stlast(*st);
			last->next = new;
		}
	}
}
