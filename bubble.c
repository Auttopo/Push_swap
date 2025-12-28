/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsam <jsam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 12:00:27 by jsam              #+#    #+#             */
/*   Updated: 2025/12/11 10:14:29 by jsam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	show_stack(t_stack **stack);

void    bubble(t_stack **s1, int size)
{
	int	i;
	int	j;

	i = 1;
	while (size > 0)
	{
		if ((*s1)->value > (*s1)->next->value)
			swap(s1, "sa");
		rotate(s1, r_next, "ra");
		if (i == size - 1)
		{
			j = 1;
			 while ( j <= size - i)
			 {
				 rotate(s1, r_next, "ra");
				 j++;
			 }
			 i = 1;
			 size--;
		}
//		i++;

	}
}
