/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenabde <abenabde@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:15:11 by abenabde          #+#    #+#             */
/*   Updated: 2026/01/20 12:15:11 by abenabde         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	compare(t_info *d, t_stack **s1, char *str)
{
	if ((*s1)->value > (*s1)->next->value)
		swap(d, s1, str);
}

static void	sort_pair_reverse(t_info *d, t_stack **s1, int size, char *str)
{
	int		i;
	char	*st;

	i = 0;
	st = "sb";
	if (str[2] == 'a')
		st = "sa";
	while (1)
	{
		if (compute_disorder((*s1)) == 0)
			return ;
		if (i < size)
		{
			compare(d, s1, st);
			if (compute_disorder((*s1)) == 0)
				return ;
			rotate(d, s1, r_prev, str);
		}
		else
		{
			rotate(d, s1, r_prev, str);
			i = 0;
		}
		i++;
	}
}

static void	merge_setup(t_info d, t_stack *local)
{
	int		i;
	int		number_per_bucket;

	i = 0;
	number_per_bucket = d.total / 2;
	while (i < (d.total - number_per_bucket))
	{
		local->bucket = 1;
		local = local->next;
		i++;
	}
	while (i < d.total)
	{
		local->bucket = 2;
		local = local->next;
		i++;
	}
}

void	merge_short(t_info *d, t_stack **stack, t_stack **pull)
{
	int		e;
	int		pos;

	e = 0;
	pos = 0;
	merge_setup(*d, *stack);
	while (pos != -1)
	{
		pos = first_select(d->currentot, *stack, 2);
		if (pos == -1)
			break ;
		efficient_move(d, stack, "ra", pos);
		push(d, pull, stack, "pb");
		e++;
	}
	sort_pair_reverse(d, stack, d->total - (d->total / 2), "rra");
	sort_pair_reverse(d, pull, d->total / 2, "rrb");
	while (*pull != NULL)
	{
		push(d, stack, pull, "pa");
	}
	sort_pair_reverse(d, stack, d->total, "rra");
}
