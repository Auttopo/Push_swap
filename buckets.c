/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buckets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenabde <abenabde@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 13:41:48 by abenabde          #+#    #+#             */
/*   Updated: 2025/12/30 13:41:48 by abenabde         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

static int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	while ((i * i) <= nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (i - 1);
}

static int	buk_select(t_info d, t_stack *local, int buck)
{
	int		i;
	int	nbr_buk;
	int	range;

	range = (d.max - d.min);
	i = 0;
	while (i < d.total)
	{
		if (local->value < (d.max - (range / d.buk_nbr * buck)))
			return (i);
		local = local->next;
		i++;
	}
	return (-1);
}

void	buckets(t_info d, t_stack **stack, t_stack **pull)
{
	int		i;
	int		e;
	long	comp;
	int		pos;
	int		buck;


	d.buk_nbr = ft_sqrt(d.total);
	buck = d.buk_nbr - 1;
	__builtin_printf("%d buk | %ld range\n", d.buk_nbr, d.max - d.min);
	while (e < d.total)
	{
		pos = buk_select(d, *stack, buck);
		if (pos == -1)
			buck--;

		if (pos < (d.total / 2))
		{
			while ((long)(*stack)->value != comp)
				rotate(stack, r_next, "ra");
		}
		else
		{
			while ((long)(*stack)->value != comp)
				rotate(stack, r_prev, "rra");
		}

		push(pull, stack, "pb");
		e++;
	}
/*	e = 0;
	while (e < d.total - 1)
	{
		push(stack, pull, "pa");
		e++;
	}*/
}
