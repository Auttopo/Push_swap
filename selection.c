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

void	selection(int total, t_stack **stack, t_stack **pull)
{
	int		i;
	int		e;
	long	comp;
	int		pos;

	e = 0;
	while (e < total - 1)
	{
		comp = min_select(total, *stack, &pos);
		efficient_move(total, stack, "ra", pos);

		push(pull, stack, "pb");

		e++;
	}
	e = 0;
	while (e < total - 1)
	{
		push(stack, pull, "pa");
		e++;
	}
}
