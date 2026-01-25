/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsam <jsam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 09:32:04 by jsam              #+#    #+#             */
/*   Updated: 2026/01/25 14:22:07 by jsam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	min_indexing(int total, t_stack *local, int x)
{
	t_stack	*temp;
	long	comp;
	int		i;

	comp = 3000000000;
	i = 0;
	while (i < total)
	{
		if (((long)local->value < comp) && (local->index == -1))
		{
			temp = local;
			comp = (long)local->value;
		}
		local = local->next;
		i++;
	}
	temp->index = x;
}

void	init_index(t_stack *stack, int size)
{
	int	i;

	i = 1;
	while (i <= size)
	{
		min_indexing(size, stack, i);
		i++;
	}
}

int	find_max(int size, int base)
{
	int	i;

	i = 0;
	while (size % base || size / base)
	{
		size = size / base;
		i++;
	}
	return (i);
}

char	*definestr_rotate(int min_max, int i, int base)
{
	char	*str;

	if (min_max < 0 && i < 0 && base != 2)
		str = "rra";
	else if (min_max < 0 && i > 0)
		str = "ra";
	else if (min_max > 0 && i < 0 && base != 2)
		str = "rrb";
	else
		str = "rb";
	return (str);
}

t_stack	*find_minmax(t_stack *pstack, int min_max)
{
	t_stack	*tmp;
	t_stack	*result;

	if (!pstack)
		return (NULL);
	result = pstack;
	tmp = pstack->next;
	if (result == tmp)
		return (result);
	while (tmp != pstack)
	{
		if (((tmp->index % 10) * min_max > ((result->index % 10) * min_max)))
			result = tmp;
		tmp = tmp->next;
	}
	return (result);
}
