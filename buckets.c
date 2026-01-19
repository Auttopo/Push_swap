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

t_stack	*max_nod_select(int total, t_stack *local)
{
	t_stack	*temp;
	int		i;
	long	comp;

	i = 0;
	comp = -3000000000;
	temp = NULL;
	while (i < total)
	{
		if (local->bucket == 0 && (long)local->value > comp)
		{
			temp = local;
			comp = temp->value;
		}
		local = local->next;
		i++;
	}
	return (temp);
}

void	buk_setup(t_info d, t_stack *local, t_stack *(*select)(int, t_stack*))
{
	t_stack	*temp;
	int		buk_nbr_tmp;
	int		i;
	int		number_per_bucket;

	number_per_bucket = d.total / d.buk_nbr;
	i = 0;
	buk_nbr_tmp = d.buk_nbr;
	while (buk_nbr_tmp != 0)
	{
		temp = select(d.total, local);
		temp->bucket = buk_nbr_tmp;
		i++;
		if (i == number_per_bucket)
		{
			i = 0;
			buk_nbr_tmp -= 1;
		}
	}
	while (temp != NULL)
	{
		temp->bucket = 1;
		temp = max_nod_select(d.total, local);
	}
}

static int	value_select(int st_tot, t_stack *local, int buck)
{
	int		pos;
	int		i;
	int		moves;

	i = 0;
	moves = 0;
	while (local->previous->bucket == buck && buck != 1)
	{
		local = local->previous;
		moves++;
	}
	pos = max_in_bucket(local, buck);
	if (pos != -1)
	{
		pos = pos - moves;
		if (pos < 0)
		{
			pos = st_tot + pos;
		}
	}
	return (pos);
}

static void	value_sorter(t_info *d, t_stack **stack, t_stack **pull)
{
	int	i;
	int	buck;
	int	pos;

	i = 0;
	buck = d->buk_nbr;
	while (i < d->total && buck > 0)
	{
		pos = value_select(d->currentot, *pull, buck);
		if (pos == -1)
		{
			buck--;
			continue ;
		}
		efficient_move(d, pull, "rb", pos);
		push(d, stack, pull, "pa");
		i++;
	}
	d->currentot = d->total;
}

void	buckets(t_info *d, t_stack **stack, t_stack **pull)
{
	int		e;
	int		pos;
	int		buck;

	e = 0;
	buck = 1;
	buk_setup(*d, *stack, max_nod_select);
	while (e < d->total)
	{
		pos = first_select(d->total, *stack, buck);
		if (pos == -1)
		{
			buck++;
			continue ;
		}
		efficient_move(d, stack, "ra", pos);
		push(d, pull, stack, "pb");
		e++;
	}
	d->currentot = d->total;
	value_sorter(d, stack, pull);
}
