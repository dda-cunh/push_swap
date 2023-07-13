/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:15:14 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/07/13 15:13:05 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	clear_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a)
		stclear(stack_a);
	if (stack_b)
		stclear(stack_b);
}

int	print_error(t_stack *stack_a, t_stack *stack_b)
{
	clear_stacks(stack_a, stack_b);
	ft_putstr_fd("Error\n", 2);
	return (1);
}

int	sthasle(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value <= value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	stackissort(t_stack *stack, int size)
{
	int	i;

	i = 0;
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		i++;
		stack = stack->next;
	}
	return (i + 1 == size);
}

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
