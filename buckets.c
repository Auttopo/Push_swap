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

int	ft_sqrt(int nb)
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

int	max_in_bucket(t_stack *local, int buck)
{
	long	comp;
	int		i;
	int		pos;

	comp = -3000000000;
	i = 0;
	pos = -1;
	while (local->bucket == buck && local->value != comp)
	{
		if ((long)local->value > comp)
		{
			comp = local->value;
			pos = i;
		}
		local = local->next;
		i++;
	}
	return (pos);
}

static	t_stack	*max_nod_select(int	total, t_stack *local)
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

void	buk_setup(t_info d, t_stack *local)
{
	t_stack *temp;
	int		buk_nbr_tmp;
	int		i;
	int		number_per_bucket;

	number_per_bucket = d.total / d.buk_nbr;
	i = 0;
	buk_nbr_tmp = d.buk_nbr;
	while (buk_nbr_tmp != 0)
	{
		temp = max_nod_select(d.total, local);
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

void	efficient_move(int total, t_stack **stack, char *str, int pos)
{
	int	i;
	char	*strr;

	i = 0;
	strr = "rrb";
	if (str[1] == 'a')
		strr = "rra";
	if (pos < (total / 2))
	{
		while (i < pos)
		{
			rotate(stack, r_next, str);
			i++;
		}
	}
	else
	{
		while ((total - i) != pos)
		{
			rotate(stack, r_prev, strr);
			i++;
		}
	}
}

int	value_select(int st_tot, t_stack *local, int buck)
{
	long	comp;
	int		pos;
	int		i;
	int		moves;

	i = 0;
	moves = 0;
	comp = (long)local->next->value;
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

void	value_sorter(t_info d, t_stack **stack, t_stack **pull)
{
	t_stack *start;
	int	i;
	int	buck;
	int	pos;
	int	st_tot;

	i = 0;
	buck = d.buk_nbr;
	st_tot = d.total;
	while (i < d.total && buck > 0)
	{
		pos = value_select(st_tot, *pull, buck);
		if (pos == -1)
		{
			buck--;
			continue;
		}
		efficient_move(st_tot, pull, "rb", pos);
		push(stack, pull, "pa");
		st_tot -= 1;
		i++;
	}
}

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
	buk_setup(*d, *stack);
	while (e < d->total)
	{
		pos = first_select(*d, *stack, &comp, buck);
		if (pos == -1)
		{
			buck++;
			continue;
		}
		efficient_move(d->currentot, stack, "ra", pos);
		d->currentot -= 1;
		push(pull, stack, "pb");
		e++;
	}
	d->currentot = d->total;
	value_sorter(*d, stack, pull);
}
