/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:09:04 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/05/07 23:04:59 by dda-cunh         ###   ########.fr       */
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

// void	print_stacks(t_stack *a, t_stack *b)
// {
// 	int	i;

// 	i = -1;
// 	ft_putstr_fd("\tA\t\tB\n", 1);
// 	while (a || b)
// 	{
// 		ft_putchar_fd('\t', 1);
// 		if (a)
// 		{
// 			ft_putnbr_fd(a->value, 1);
// 			a = a->next;
// 		}
// 		ft_putstr_fd("\t\t", 1);
// 		if (b)
// 		{
// 			ft_putnbr_fd(b->value, 1);
// 			b = b->next;
// 		}
// 		ft_putchar_fd('\n', 1);
// 	}
// }

static void	plus30(t_stack **a, t_stack **b, int ac)
{
	int	mid;

	mid = get_mid(a, ac);
	while (currsize(*a) >= currsize(*b))
	{
		if (a && *a && (*a)->value <= mid)
		{
			paob(b, a, 'b');
			if (b && *b && (*b)->value < stlast(*b)->value)
				rr(a, b, 0);
		}
		else
		{
			if (b && *b && (*b)->value < stlast(*b)->value)
				rr(a, b, 0);
			else
				raob(a, 'a');
		}
	}
	both_top(a, b, ac - 1);
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
		plus30(&a, &b, ac);
	else
	{
		while (!stackissort(a, ac - 1))
		{
			if (!atob(&a, &b, ac - 1))
				btoa(&a, &b, ac - 1);
			else
				break ;
		}
	}
	clear_stacks(a, b);
	return (0);
}
