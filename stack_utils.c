/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:12:42 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/05/08 18:39:22 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	currsize(t_stack *stack)
{
	int	i;

	if (!stack)
		return (0);
	i = 1;
	while (stack->next)
	{
		stack = stack->next;
		i++;
	}
	return (i);
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

void	print_stacks(t_stack *a, t_stack *b)
{
	ft_putstr_fd("\tA\t\tB\n", 1);
	while (a || b)
	{
		ft_putchar_fd('\t', 1);
		if (a)
		{
			ft_putnbr_fd(a->value, 1);
			a = a->next;
		}
		ft_putstr_fd("\t\t", 1);
		if (b)
		{
			ft_putnbr_fd(b->value, 1);
			b = b->next;
		}
		ft_putchar_fd('\n', 1);
	}
}
