/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenabde <abenabde@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 14:29:25 by abenabde          #+#    #+#             */
/*   Updated: 2026/01/18 14:29:25 by abenabde         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	compare(t_info *d, t_stack **s1)
{
	if ((*s1)->value > (*s1)->next->value)
	{
		swap(d, s1, "sa");
		rotate(d, s1, r_next, "ra");
	}
	else
		rotate(d, s1, r_next, "ra");
}

void	bubble(t_info *d, t_stack **s1, int size)
{
	int	n;
	int	i;
	int	j;
	int	k;

	n = size - 1;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < n)
		{
			compare(d, s1);
			j++;
		}
		i++;
		n--;
		k = 0;
		while (k < i)
		{
			rotate(d, s1, r_next, "ra");
			k++;
		}
	}
}
