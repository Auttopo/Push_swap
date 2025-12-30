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

static int	buk_select(t_info d, t_stack *local, int buck, long *comp)
{
	int		i;
	int	nbr_buk;
	int	range;

	range = (d.max - d.min);
	i = 0;
	while (i < d.total)
	{
		__builtin_printf("%d value | %ld buck limit\n", local->value, (d.max - ((range / d.buk_nbr) * buck)));
		__builtin_printf("%ld MAX ; %d RANGE ; %d BUCKS ; %d buck\n\n", d.max, range, d.buk_nbr, buck);

		if ((float)local->value < ((float)d.max - (((float)range / (float)d.buk_nbr) * (float)buck)))
		{
			*comp = local->value;
			return (i);
		}
		local = local->next;
		i++;
	}
	*comp = 3000000000;
	return (-1);
}

void	buckets(t_info d, t_stack **stack, t_stack **pull)
{
	int		i;
	int		e;
	long	comp;
	int		pos;
	int		buck;


	e = 0;
	d.buk_nbr = ft_sqrt(d.total);
	buck = d.buk_nbr - 1;
	__builtin_printf("%ld buk | %ld range\n", d.min, d.max - d.min);
	while (e < d.total)
	{
		pos = buk_select(d, *stack, buck, &comp);
		if (pos == -1)
		{
			buck--;
			continue;
		}
		if (pos == -1 && comp == 3000000000)
		{
			__builtin_printf("\nSOMETHING GONE SERIOUSLY WRONG !\n");
			return ;
		}
		i = -1;
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
