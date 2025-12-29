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

void	selection(int total, t_stack **stack, t_stack **pull)
{
	t_stack	*local;
	int		i;
	long	comp;
	long	max;
	int		pos;

	int e = 0;
	while (e < total - 1)
	{
		max = 3000000000;
		comp = max;
		local = *stack;
		i = 0;
		while (i < total)
		{
			if ((long)local->value < comp)
			{
				pos = i;
				comp = (long)local->value;
			}
			local = local->next;
			i++;
		}

		i = 0;
		while (i < pos)
		{
			rotate(stack, r_next, "MOV");
			i++;
		}
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
