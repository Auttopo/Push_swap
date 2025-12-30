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

#include <stdlib.h>
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

static	int	first_select(t_info d, t_stack *local, long *comp, int buck)
{
	int		i;
	
	i = 0;
	while (i < d.total)
	{
		if (local->bucket == buck)
		{
			*comp = (long)local->value;
			return (i);
		}
		local = local->next;
		i++;
	}
	*comp = 3000000000;
	return (-1);
}

static	t_stack	*all_select(int	total, t_stack *local, int buck)
{
	t_stack	*temp;
	int		i;
	long	comp;
	
	i = 0;
	comp = -3000000000;
	temp = NULL;
	while (i < total)
	{
		if (local->bucket == buck && (long)local->value > comp)
		{
			temp = local;
			comp = temp->value;
		}
		local = local->next;
		i++;
	}
	return (temp);
}

void	buk_setup(t_info d, t_stack *local)
{
	t_stack *temp;
	int		buk_nbr_tmp;
	int		i;

	i = 0;
	buk_nbr_tmp = d.buk_nbr;
	while (buk_nbr_tmp != 0)
	{
		temp = (all_select(d.total, local, 0));
		temp->bucket = buk_nbr_tmp;
		i++;
		if (i == d.buk_nbr)
		{
			i = 0;
			buk_nbr_tmp -= 1;
		}
	}
	buk_nbr_tmp = 1;
	while (temp != NULL)
	{
		temp->bucket = buk_nbr_tmp;
		temp = (all_select(d.total, local, 0));
	}
}
/*
void	value_select()
{
	
}

void	value_sorter(t_info d, t_stack **stack, t_stack **pull)
{
	t_stack *start;
	int	e;

	e = 0;
	while (e < d.total - 0)
	{
		all_select
		push(stack, pull, "pa");
		e++;
	}
}
*/
void	buckets(t_info *d, t_stack **stack, t_stack **pull)
{
	int		i;
	int		e;
	long	comp;
	int		pos;
	int		buck;


	e = 0;
	buck = 1;
	comp = -3000000000;
	d->buk_nbr = ft_sqrt(d->total);

	buk_setup(*d, *stack);

	while (e < d->total)
	{
		pos = first_select(*d, *stack, &comp, buck);
		if (pos == -1)
		{
			buck++;
			continue;
		}
//		if (pos == -1 && comp == 3000000000)
//		{
//			__builtin_printf("\nSOMETHING GONE SERIOUSLY WRONG !\n");
//			return ;
//		}
//		i = -1;

		if (pos < (d->total / 2))
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
}
