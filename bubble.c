/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsam <jsam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 12:00:27 by jsam              #+#    #+#             */
/*   Updated: 2025/12/28 19:13:28 by jsam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void    bubble(t_stack **s1, int size)
{
	int	n;
	int	i;
	int	j;
	int	k;

	n = size;
	i = 0;

	while (i < size)
	{
		j = 0;
		while (j < n)
		{
			if((*s1)->value > (*s1)->next->value)
			{
				swap(s1, "sa");
				rotate(s1, r_next, "ra");
			}
			else 
				rotate(s1, r_next, "ra");
			j++;
		}
		i++;
		n--;
		k = 0;
		while (k < i)
		{
			rotate(s1, r_next, "ra");
			k++;
		}
	}
}
