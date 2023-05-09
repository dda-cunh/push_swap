/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:31:11 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/05/09 18:10:17 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	top(t_stack **a, char print)
{
	if ((*a)->next && (*a)->value > (*a)->next->value)
	{
		while ((*a)->value > stlast(*a)->value)
			raob(a, print);
		if (stackissort(*a, currsize(*a)))
			return ;
		saob(a, print);
	}
}

void	mintob(t_stack **a, t_stack **b, int fake)
{
	int		rot;
	char	print;

	print = 'a';
	if (fake)
		print = '\0';
	while (*a)
	{
		top(a, print);
		if (stackissort(*a, currsize(*a)))
			return ;
		rot = min_rot(*a, currsize(*a));
		if (rot < 0)
			while (rot++)
				rraob(a, print);
		else
			while (rot--)
				raob(a, print);
		if (fake)
			paob(b, a, '\0');
		else
			paob(b, a, 'b');
	}
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
