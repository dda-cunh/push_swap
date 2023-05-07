/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:31:11 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/05/07 23:46:48 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stackisrsort(t_stack *stack, int size)
{
	int	i;

	i = 0;
	while (stack->next)
	{
		if (stack->value < stack->next->value)
			return (0);
		i++;
		stack = stack->next;
	}
	return (i + 1 == size);
}

void	btoa(t_stack **a, t_stack **b, int size)
{
	btoaxd(a, b);
	if (stackissort(*a, size - 1))
		paob(a, b, '\0');
}

int	atob(t_stack **a, t_stack **b, int size)
{
	while ((*a)->next)
	{
		dotop(a, b);
		if (stackissort(*a, size))
			return (1);
		if (stackissort(*a, currsize(*a)))
		{
			if ((*a)->value < (*b)->value)
				paob(b, a, '\0');
			if (stackisrsort(*b, currsize(*b)))
			{
				while (*b)
					paob(a, b, '\0');
				return (1);
			}
			break ;
		}
		atobxd(a, b);
	}
	return (0);
}

int	parser(int ac, char **av)
{
	int		i;
	int		j;
	int		inum;

	i = 0;
	while (++i < ac)
		if (!ft_sisint(av[i]))
			return (1);
	i = 0;
	while (++i < ac)
	{
		j = 0;
		inum = ft_atoi(av[i]);
		while (++j < ac)
		{
			if (j == i)
				continue ;
			if (ft_atoi(av[j]) == inum)
				return (1);
		}
	}
	return (0);
}

t_stack	*init_stack(int ac, char **av)
{
	int		i;
	t_stack	*stack;
	t_stack	*start;

	if ((parser(ac, av)))
		return (NULL);
	stack = stnew(ft_atoi(av[1]));
	if (!stack)
		return (NULL);
	start = stack;
	i = 1;
	while (++i < ac)
	{
		stack->next = stnew(ft_atoi(av[i]));
		if (!stack->next)
		{
			stclear(start);
			return (NULL);
		}
		stack = stack->next;
	}
	return (start);
}
