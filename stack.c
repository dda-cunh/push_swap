/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:31:11 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/05/08 22:45:07 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dotop(t_stack **a, t_stack **b)
{
	if ((*a) && (*a)->value > stlast((*a))->value)
	{
		if ((*b) && (*b)->next && ((*b)->value < stlast(*b)->value))
			joint_op(a, b, 'r');
		else
			raob(a, 'a');
	}
	if ((*b) && (*b)->value < stlast((*b))->value)
	{
		if ((*a)->next && ((*a)->value > stlast((*a))->value))
			joint_op(a, b, 'r');
		else
			raob(b, 'b');
	}
}

void	min_top(t_stack **a_head, t_stack **b_head)
{
	int		min_i;
	t_stack	*a;

	a = *a_head;
	if (a)
	{
		min_i = min_rot(a, currsize(a));
		if (min_i < 0)
			while (min_i++)
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

void	atob(t_stack **a, t_stack **b, int size)
{
	while ((*a))
	{
		dotop(a, b);
		if (stackissort(*a, size))
			return ;
		if (stackissort(*a, currsize(*a)))
			if (*b && (*a)->value > (*b)->value)
				break ;
		if ((*a)->value < (*a)->next->value)
			paob(b, a, 'b');
		else
		{
			if (*b && (*b)->next && (*b)->value < (*b)->next->value)
				joint_op(a, b, 's');
			else
				saob(a, 'a');
		}
	}
	maxtoa(a, b);
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
