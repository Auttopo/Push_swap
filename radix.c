/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsam <jsam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:23:47 by jsam              #+#    #+#             */
/*   Updated: 2026/01/10 13:39:35 by jsam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> // DELETE BEFORE PUSH

t_stack	*find_minmax(t_stack *pstack, int unit, int min_max)
{
	t_stack	*tmp;
	t_stack	*result;
	t_stack	*testnull;

	if (!pstack)
		return (NULL);
	result = pstack;
	tmp = pstack->next;
	if (result == tmp)
		return (result);
	while (tmp != pstack)
	{
		if (((tmp->index / unit) % 10) * min_max > ((result->index / unit) % 10) * min_max)
			result = tmp;
		tmp = tmp->next;
	}
	return (result);
}

void    radix_move(t_info *info, t_stack **s1, t_stack **s2, int size, char *pushstr, int min_max, char *rotatestr)
{
        t_stack *pstack;
        t_stack *pmin;
        int     i;
	int	check;

        i = 0;
        pstack = *s1;
        while (i < size)
        {
		if (*s1)
		{
			check = (*s1)->index % 2;
			if ((*s1)->index != 0)
				(*s1)->index /= 2;
		}
		if ((min_max == -1 && check == 0) || (min_max == 1 && check == 1))
			push(info, s2, s1, pushstr);
		else
			rotate(info, s1, r_next, rotatestr);
		i++;
        }
	while (*s1)
		push(info, s2, s1, pushstr);
}

int	find_max_bin(int size)
{
	int	*bin;
	int	base[2];
	int	i;

	i = 0;
	while (size % 2 || size / 2)
	{
		size = size /2;
		i++;
	}
	return (i);
}

void	radix(t_info *info, t_stack **stack, t_stack **pull, int size)
{
	t_stack	*pstack;
	t_stack	*pmin;
	int	i;
	int	max;

	i = 1;
	pstack = *stack;
	init_index(*stack, size);
	max = find_max_bin(size);
	while (i <= max)
	{
		if (i % 2 != 0)
			radix_move(info, stack, pull, size, "pb", -1, "ra");
		else
			radix_move(info, pull, stack, size, "pa", 1, "rb");
		i++;
	}
	if (!(*stack))
	{
		while (size > 0)
		{
			push(info, stack, pull, "pa");
			size--;
		}
	}
}
