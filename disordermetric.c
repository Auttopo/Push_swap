/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disordermetricabenabdejsam291235.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsam <jsam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 16:00:45 by jsam              #+#    #+#             */
/*   Updated: 2025/12/30 14:44:57 by jsam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		j = 0;
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
}
