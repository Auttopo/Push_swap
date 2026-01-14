/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disordermetric.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsam <jsam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 16:00:45 by jsam              #+#    #+#             */
/*   Updated: 2026/01/09 15:27:12 by jsam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
float compute_disorder(t_stack *s, int size)
{
	int	mistakes;
	int	total;
	int	i;
	int	tmp;
	int	j;
	int	k;
	float	metric;
	int	n;

	n = size;

	mistakes = 0;
	total = 0;
	i = 0;
	while (i < size)
	{
		tmp = s->value;
		j = i + 1;
		while (j < n)
		{
			if (s->next->value < tmp)
				mistakes++;
			s = s->next;
			total++;
			j++;
		}
		n--;
		i++;
		k = 0;
		while (k < i)
		{
			s = s->next;
			k++;
		}
	}
	metric =(float)mistakes / (float)total;
	return (metric);
}*/

float compute_disorder(t_stack *s)
{
	int	mistakes;
	int	total;
	float	metric;
	t_stack	*p1;
	t_stack *p2;
	
	p1 = s;
	mistakes = 0;
	total = 0;
	while (p1 != s->previous)
	{
		p2 = p1->next;
		while (p2 != s)
		{
			if (p1->value > p2->value)
				mistakes++;
			p2 = p2->next;
			total++;
		}
		p1 = p1->next;
	}
	if (mistakes == 0 || total == 0)
		return (0);
	metric = (float)mistakes / (float)total;
	return (metric);
}
