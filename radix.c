/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsam <jsam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:23:47 by jsam              #+#    #+#             */
/*   Updated: 2026/01/11 14:42:03 by jsam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> // TODO DELETE BEFORE PUSH

t_stack	*find_minmax(t_stack *pstack, int min_max)
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
		if (((tmp->index % 10) * min_max > ((result->index % 10) * min_max)))
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

int	radix_rotate(t_stack *pmin, t_stack *s1)
{
	int	i;
	int	j;
	t_stack	*tmp;

	tmp = s1;
	i = 0;
	j = 0;
	while (tmp != pmin)
	{
		i++;
		tmp = tmp->next;
	}
	tmp = s1;
	while (tmp != pmin)
	{
		j++;
		tmp = tmp->previous;
	}
	if (i < j)
		return (i);
	return (-j);
}

char	*definestr_rotate(int min_max, int i)
{
	char	*str;

	if (min_max < 0 && i < 0)
		str = "rra";
	else if (min_max < 0 && i > 0)
		str = "ra";
	else if (min_max > 0 && i < 0)
		str = "rrb";
	else
		str = "rb";
	return (str);
}

void    radix_move_10(t_info *info, t_stack **s1, t_stack **s2, int size, char *pushstr, int min_max)
{
        t_stack *pstack;
        t_stack *pmin;
        int     i;
        int     check;
	char	*str;

        pstack = *s1;
	if (min_max < 0)
		str = "a";
	else
		str = "b";
	/*pmin = find_minmax(pstack, min_max);
	i = radix_rotate(pmin, *s1);
	if (pstack == pmin)
		pstack = pstack->next;*/
	while (*s1)
	{
		pmin = find_minmax(pstack, min_max);
		i = radix_rotate(pmin, *s1);
		if(pstack == pmin)
			pstack = pstack->next;
        	if (i < 0)
		{
			while (i < 0)
			{
				rotate(info, s1, r_prev, definestr_rotate(min_max, i));
				i++;
			}
		}
		else
		{
			while (i > 0)
			{
				rotate(info, s1, r_next, definestr_rotate(min_max, i));
				i--;
			}
		}
		if (*s1)
			if((*s1)->index != 0)
				(*s1)->index /= 10;
		push(info, s2, s1, pushstr);
	}
}

int	find_max(int size, int base)
{
	int	*bin;
	int	i;

	i = 0;
	while (size % base || size / base)
	{
		size = size / base;
		i++;
	}
	return (i);
}

void	radix(t_info *info, t_stack **stack, t_stack **pull, int size, int base)
{
	t_stack	*pstack;
	t_stack	*pmin;
	int	i;
	int	max;

	i = 1;
	pstack = *stack;
	init_index(*stack, size);
	max = find_max(size, base);
	if(base == 2)
	{
		while (i <= max)
		{
			if (i % 2 != 0)
				radix_move(info, stack, pull, size, "pb", -1, "ra");
			else
				radix_move(info, pull, stack, size, "pa", 1, "rb");
			i++;
		}
	}
	else
	{
		while (i <= max)
		{
			if (i % 2 != 0)
				radix_move_10(info, stack, pull, size, "pb", -1);
			else
				radix_move_10(info, pull, stack, size, "pa", 1);
			i++;
		}
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
