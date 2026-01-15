/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsam <jsam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:23:47 by jsam              #+#    #+#             */
/*   Updated: 2026/01/15 12:19:00 by jsam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> // TODO DELETE BEFORE PUSH

void	radix_move(t_info *info, t_stack **s1, t_stack **s2, int min_max)
{
	int		i;
	int		check;
	char	*pushstr;

	pushstr = "pb";
	if (min_max > 0)
		pushstr = "pa";
	i = 0;
	while (i < info->total)
	{
		if (*s1)
		{
			check = (*s1)->index;
			if ((*s1)->index != 0)
				(*s1)->index /= 2;
			if ((min_max == -1 && check % 2 == 0)
				|| (min_max == 1 && check % 2 == 1))
				push(info, s2, s1, pushstr);
			else
				rotate(info, s1, r_next, definestr_rotate(min_max, 1, 2));
		}
		i++;
	}
	while (*s1)
		push(info, s2, s1, pushstr);
}

int	radix_find_mincheck(t_stack *pmin, t_stack *s1)
{
	int		i;
	int		j;
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

void	radix_rotate(t_info *info, t_stack **s1, t_stack **pstack, int min_max)
{
	t_stack	*pmin;
	int		mincheck;
	int		absol;

	pmin = find_minmax(*pstack, min_max);
	mincheck = radix_find_mincheck(pmin, *s1);
	absol = mincheck;
	if (mincheck < 0)
		absol *= -1;
	if (*pstack == pmin)
		*pstack = (*pstack)->next;
	while (absol > 0)
	{
		if (mincheck < 0)
			rotate(info, s1, r_prev, definestr_rotate(min_max, -1, 10));
		else
			rotate(info, s1, r_next, definestr_rotate(min_max, 1, 10));
		absol--;
	}
}

void	radix_move_10(t_info *info, t_stack **s1, t_stack **s2, int min_max)
{
	t_stack	*pstack;
	char	*pushstr;

	pstack = *s1;
	pushstr = "pa";
	if (min_max < 0)
		pushstr = "pb";
	while (*s1)
	{
		radix_rotate(info, s1, &pstack, min_max);
		if (*s1)
			if ((*s1)->index != 0)
				(*s1)->index /= 10;
		push(info, s2, s1, pushstr);
	}
}

void	radix(t_info *info, t_stack **stack, t_stack **pull, int base)
{
	t_stack	*pstack;
	int		i;
	int		max;
	void	(*pf)(t_info*, t_stack**, t_stack**, int);

	i = 1;
	pstack = *stack;
	init_index(*stack, info->total);
	max = find_max(info->total, base);
	pf = radix_move;
	if (base == 10)
		pf = radix_move_10;
	while (i <= max)
	{
		if (i % 2 != 0)
			pf(info, stack, pull, -1);
		else
			pf(info, pull, stack, 1);
		i++;
	}
	if (!(*stack))
	{
		while (*pull)
			push(info, stack, pull, "pa");
	}
}
