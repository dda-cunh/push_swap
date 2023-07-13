/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:09:04 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/07/13 22:36:51 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <limits.h>

// #include <iostream>

// int	main(int ac, char **av)
// {
// 	if (ac == 2)
// 	{
// 		srand((unsigned) time(NULL));
// 		freopen("output.txt", "w", stdout);
// 		for (int i = 0; i < atoi(av[1]); i++)
// 			std::cout << (int)rand() << " ";
// 		return (0);
// 	}
// 	return (1);
// }

// static void	loe3(t_stack **a, t_stack **b)
// {
// 	if (!stackissort(*a, currsize(*a)))
// 	{
// 		mintob(a, b, 0, 1);
// 		if (!stackissort(*a, currsize(*a)))
// 			saob(a, 'a');
// 		paob(a, b, 'a');
// 	}
// 	return ;
// }

// static void	loe5(t_stack **a, t_stack **b)
// {
// 	mintob(a, b, 0, 2);
// 	loe3(a, b);
// 	return ;
// }

static int	ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

int	best_rot_a(t_stack *stack, int size, int max)
{
	int		i;
	int		j;

	if (!stackissort(stack, size))
	{
		i = 0;
		j = size / 2;
		while (stack)
		{
			if (stack->value <= max
				&& (ft_abs(i - (size / 2)) > ft_abs(j - (size / 2))))
				j = i;
			stack = stack->next;
			i++;
		}
		if (j > size / 2)
			return (j - size);
		else
			return (j);
	}
	return (0);
}

static void	plus30(t_stack **a, t_stack **b, int size)
{
	int	flag;
	int	mid;
	int	rot;

	mid = get_mid(*a, size);
	while (sthasle(*a, mid))
	{
		flag = 0;
		rot = best_rot_a(*a, currsize(*a), mid);
		if (rot < 0)
			while (rot++)
				rraob(a, 'a');
		else
		{
			while (rot--)
			{
				if (b && *b && flag < (currsize(*b) + 1) / currsize(*b))
				{
					joint_op(a, b, 'r');
					flag++;
				}
				else
					raob(a, 'a');
			}
		}
		paob(b, a, 'b');
	}
	if (!stackissort(*a, currsize(*a)))
		plus30(a, b, currsize(*a));
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (1);
	a = init_stack(ac, av);
	if (!a)
		return (print_error(NULL, NULL));
	b = NULL;
	if (ac > 31)
		plus30(&a, &b, ac - 1);
	else
		mintob(&a, &b, 0, -1);
	maxtoa(&a, &b, 0);
	clear_stacks(a, b);
	return (0);
}
