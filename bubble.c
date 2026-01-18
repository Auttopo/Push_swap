/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenabde <abenabde@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 14:29:25 by abenabde          #+#    #+#             */
/*   Updated: 2026/01/18 16:22:56 by jsam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	compare(t_info *d, t_stack **s1)
{
	if ((*s1)->value > (*s1)->next->value)
	{
		swap(d, s1, "sa");
	}
}

void	bubble(t_info *d, t_stack **s1, int size)
{
	int i = -2;
	if (size < 3)
	{
		compare(d, s1);	
		return ;
	}
	while (1)
	{
		if (i < size - 0)
		{
			compare(d, s1);	
			if (compute_disorder((*s1)) == 0)
			{
				return ;
			}
			rotate(d, s1, r_prev, "rra");
		}
		else
		{
			rotate(d, s1, r_prev, "rra");
			i = 0;
		}
		i++;
	}
}

static t_stack	*min_nod_select(int total, t_stack *local)
{
	t_stack	*temp;
	int		i;
	long	comp;

	i = 0;
	comp = 3000000000;
	temp = NULL;
	while (i < total)
	{
		if (local->bucket == 0 && (long)local->value < comp)
		{
			temp = local;
			comp = temp->value;
		}
		local = local->next;
		i++;
	}
	return (temp);
}

static void	half_selection(t_info *d, int total, t_stack **stack, t_stack **pull)
{
	int		e;
	int		pos;

	e = 0;
	d->currentot = total;
	while (e < total)
	{
		pos = max_in_bucket(*pull, 2);
		efficient_move(d, pull, "rb", pos);
		push(d, stack, pull, "pa");
		e++;
	}
}

void	merge_bubble(t_info *d, t_stack **stack, t_stack **pull)
{
	int		e;
	int		pos;

	e = 0;
	d->buk_nbr = 2;
	buk_setup(*d, *stack, min_nod_select);
	while (e < d->total)
	{
		pos = first_select(d->currentot, *stack, 2);
		if (pos == -1)
		{
			break ;
		}
		efficient_move(d, stack, "ra", pos);
		push(d, pull, stack, "pb");
		e++;
	}
	bubble(d, stack, d->total - (d->total / d->buk_nbr));
	half_selection(d, (d->total / d->buk_nbr), stack, pull);
}


