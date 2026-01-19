/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buckets_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenabde <abenabde@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:23:10 by abenabde          #+#    #+#             */
/*   Updated: 2026/01/13 11:23:10 by abenabde         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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

void	efficient_move(t_info *d, t_stack **stack, char *str, int pos)
{
	int		i;
	char	*strr;

	i = 0;
	strr = "rrb";
	if (str[1] == 'a')
		strr = "rra";
	if (pos < (d->currentot / 2) && d->currentot != 1)
	{
		while (i < pos)
		{
			rotate(d, stack, r_next, str);
			i++;
		}
	}
	else if (d->currentot != 1)
	{
		while ((d->currentot - i) != pos)
		{
			rotate(d, stack, r_prev, strr);
			i++;
		}
	}
	d->currentot -= 1;
}

int	first_select(int total, t_stack *local, int buck)
{
	int		i;
	int		pos_next;
	int		pos_prev;

	i = 0;
	pos_next = -1;
	pos_prev = -1;
	while (i < total)
	{
		if (local->bucket == buck && pos_next == -1)
			pos_next = i;
		local = local->next;
		i++;
	}
	i = 0;
	while (i < total)
	{
		if (local->bucket == buck)
			pos_prev = i;
		local = local->next;
		i++;
	}
	if (pos_next > pos_prev && pos_next != -1)
		return (total - pos_prev);
	return (pos_next);
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
