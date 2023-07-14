/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:01:54 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/07/14 02:08:46 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// void	print_ideal_i(t_stack *a)
// {
// 	while (a)
// 	{
// 		ft_putnbr_fd(a->ideal_index, 1);
// 		ft_putendl_fd("", 1);
// 		a = a->next;
// 	}
// 	return ;
// }

static int	get_i(int val, t_stack *c)
{
	int	i;

	i = 0;
	while (c)
	{
		if (c->value == val)
			return (i);
		i++;
		c = c->next;
	}
	return (-1);
}

void	get_ideal_i(t_stack **a)
{
	t_stack	*head;
	t_stack	*c;
	t_stack	*d;

	head = *a;
	c = init_c(*a);
	d = NULL;
	mintob(&c, &d, 1, -1);
	maxtoa(&c, &d, 1);
	while (*a)
	{
		(*a)->ideal_index = get_i((*a)->value, c);
		*a = (*a)->next;
	}
	clear_stacks(c, d);
	*a = head;
	return ;
}
