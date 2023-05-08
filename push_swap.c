/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:09:04 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/05/08 22:59:44 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

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

static void	plus30(t_stack **a, t_stack **b, int size)
{
	int	mid;

	mid = get_mid(a, size);
	while (sthasle(*a, mid))
	{
		if (a && *a && (*a)->value <= mid)
		{
			if ((*a)->next && (*a)->next->value < (*a)->value)
				saob(a, 'a');
			paob(b, a, 'b');
		}
		else
		{
			if (b && *b && (*b)->next && (*b)->value > stlast(*b)->value)
				joint_op(a, b, 'r');
			else
				raob(a, 'a');
		}
	}
	if ((*a))
		plus30(a, b, currsize(*a));
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (print_error(NULL, NULL));
	a = init_stack(ac, av);
	if (!a)
		return (print_error(NULL, NULL));
	b = NULL;
	if (ac > 31)
	{
		plus30(&a, &b, ac - 1);
		maxtoa(&a, &b);
	}
	else
		atob(&a, &b, ac - 1);
	clear_stacks(a, b);
	return (0);
}
