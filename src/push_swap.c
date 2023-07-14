/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:09:04 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/07/14 15:18:53 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	loe2(t_stack **a)
{
	if (a && *a && stackissort(*a, currsize(*a)))
		return ;
	if (a && *a && currsize(*a) == 1)
		return ;
	saob(a, 'a');
}

static void	loe3(t_stack **a)
{
	if (stackissort(*a, currsize(*a)))
		return ;
	if (currsize(*a) < 3)
		return (loe2(a));
	if ((*a)->value < (*a)->next->value && (*a)->next->value
		> stlast(*a)->value && stlast(*a)->value > (*a)->value)
	{
		saob(a, 'a');
		raob(a, 'a');
	}
	else if ((*a)->value > (*a)->next->value && (*a)->next->value
		< stlast(*a)->value && stlast(*a)->value > (*a)->value)
		saob(a, 'a');
	else if ((*a)->value < (*a)->next->value && (*a)->next->value
		> stlast(*a)->value && stlast(*a)->value < (*a)->value)
		rraob(a, 'a');
	else if ((*a)->value > (*a)->next->value && (*a)->next->value
		< stlast(*a)->value && stlast(*a)->value < (*a)->value)
		raob(a, 'a');
	else
	{
		saob(a, 'a');
		rraob(a, 'a');
	}
	return ;
}

// static int	ft_abs(int n)
// {
// 	if (n < 0)
// 		n *= -1;
// 	return (n);
// }

// int	best_rot_a(t_stack *stack, int size, int max)
// {
// 	int		i;
// 	int		j;

// 	if (!stackissort(stack, size))
// 	{
// 		i = 0;
// 		j = size / 2;
// 		while (stack)

// 		{
// 			if (stack->value <= max
// 				&& (ft_abs(i - (size / 2)) > ft_abs(j - (size / 2))))
// 				j = i;
// 			stack = stack->next;
// 			i++;
// 		}
// 		if (j > size / 2)
// 			return (j - size);
// 		else
// 			return (j);
// 	}
// 	return (0);
// }

// static void	top(t_stack **a, t_stack **b, int mid)
// {
// 	(void) b;
// 	while (a && *a && (*a)->value > mid)
// 	{
// 		if ((*a)->value > (*a)->next->value && (*a)->next->value
// 			< stlast(*a)->value && (*a)->next->value <= mid)
// 		{
// 			saob(a, 'a');
// 			break ;
// 		}
// 		else if ((*a)->value > (*a)->next->value && (*a)->next->value
// 			> stlast(*a)->value && stlast(*a)->value <= mid)
// 		{
// 			rraob(a, 'a');
// 			break ;
// 		}
// 		raob(a, 'a');
// 	}
// }

static void	sort(t_stack **a, t_stack **b, int size)
{
	int	mid;

	mid = get_mid(*a, size);
	while (sthasle(*a, mid) && currsize(*a) > 10)
	{
		while (a && *a && (*a)->value > mid)
			raob(a, 'a');
		paob(b, a, 'b');
	}
	if (!stackissort(*a, currsize(*a)))
	{
		if (currsize(*a) <= 10)
		{
			mintob(a, b, 0, currsize(*a) - 3);
			return (loe3(a));
		}
		sort(a, b, currsize(*a));
	}
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
	sort(&a, &b, ac - 1);
	maxtoa(&a, &b, 0);
	clear_stacks(a, b);
	return (0);
}
