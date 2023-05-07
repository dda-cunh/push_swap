/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:15:14 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/05/06 14:11:56 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

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

t_stack	*remove_top(t_stack *stack)
{
	t_stack	*next;

	if (stack)
	{
		next = stack->next;
		free(stack);
		return (next);
	}
	return (stack);
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

