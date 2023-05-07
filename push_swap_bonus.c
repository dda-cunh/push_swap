/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 21:22:48 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/05/06 12:13:59 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	result(int ac, t_stack *sa)
{
	if (stackissort(sa, ac - 1))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

static	int	try_2(char *op, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(op, "sa", 3))
		saob(a, '\0');
	else if (!ft_strncmp(op, "sb", 3))
		saob(b, '\0');
	else if (!ft_strncmp(op, "ss", 3))
		ss(a, b, 1);
	else if (!ft_strncmp(op, "pa", 3))
		paob(a, b, '\0');
	else if (!ft_strncmp(op, "pb", 3))
		paob(b, a, '\0');
	else if (!ft_strncmp(op, "ra", 3))
		raob(a, '\0');
	else if (!ft_strncmp(op, "rb", 3))
		raob(b, '\0');
	else if (!ft_strncmp(op, "rr", 3))
		rr(a, b, 1);
	else
		return (1);
	return (0);
}

static	int	try(char *op, t_stack **a, t_stack **b)
{
	if (ft_strlen(op) == 2)
		return (try_2(op, a, b));
	else if (ft_strlen(op) == 3)
	{
		if (!ft_strncmp(op, "rra", 4))
			rraob(a, '\0');
		else if (!ft_strncmp(op, "rrb", 4))
			rraob(b, '\0');
		else if (!ft_strncmp(op, "rrr", 4))
			rrr(a, b, 1);
		else
			return (1);
	}
	else
		return (1);
	return (0);
}


int	main(int ac, char **av)
{
	t_stack	*sa;
	t_stack	*sb;
	char	*op;

	if (parser(ac, av))
		return (print_error(NULL, NULL));
	sa = init_stack(ac, av);
	if (!sa)
		return (print_error(NULL, NULL));
	sb = NULL;
	op = "";
	while (op)
	{
		op = get_next_line(STDOUT_FILENO);
		if (op)
		{
			if (try(op, &sa, &sb))
			{
				free(op);
				return (print_error(sa, sb));
			}
			free(op);
		}
	}
	result(ac, sa);
	clear_stacks(sa, sb);
	return (0);
}
