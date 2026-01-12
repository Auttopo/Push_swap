/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenabde <abenabde@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:31:33 by abenabde          #+#    #+#             */
/*   Updated: 2025/12/10 13:31:33 by abenabde         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	min_select(int total, t_stack *local, int *pos)
{
	long	comp;
	int		i;

	comp = 3000000000;
	i = 0;
	while (i < total)
	{
		if ((long)local->value < comp)
		{
			*pos = i;
			comp = (long)local->value;
		}
		local = local->next;
		i++;
	}
	return (comp);
}

void	selection(t_info *d, t_stack **stack, t_stack **pull)
{
	int		i;
	int		e;
	long	comp;
	int		pos;

	e = 0;
	while (e < d->total - 1)
	{
		comp = min_select(d->total, *stack, &pos);
		efficient_move(d, stack, "ra", pos);
		push(d, pull, stack, "pb");

		e++;
	}
	e = 0;
	while (e < d->total - 1)
	{
		push(d, stack, pull, "pa");
		e++;
	}
}
