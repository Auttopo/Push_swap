/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsam <jsam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:23:47 by jsam              #+#    #+#             */
/*   Updated: 2026/01/04 19:57:12 by jsam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> // DELETE BEFORE PUSH

//return ptr node min for one unit (if unit == 1 then find min (value / 1) % 10. if unit == 10 then find min (value/10) % 10)
t_stack	*find_min(t_stack *pstack, int unit)
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
		if (!((tmp->value / unit) % 10) && !(tmp->value / 10) && !((result->value / unit) % 10) && !(result->value / 10) )
		{
			testnull = NULL;
			add_back_nod(&testnull, new_elem(tmp->value));
			add_back_nod(&testnull, new_elem(result->value));
			testnull = find_min(testnull, unit / 10);
			if (testnull->value == tmp->value)
				result = tmp;
		}
		if ((tmp->value / unit) % 10  < (result->value / unit) % 10)
			result = tmp;
		tmp = tmp->next;
	}
	return (result);
}
//same but for pull (we have to keep the same order to find min with radix, pull is reversed so we need to parse other side)
/*t_stack	*find_pull(t_stack *pstack, int unit)
{
	t_stack	*tmp;
	t_stack	*result;

	if (!pstack)
		return (NULL);
	result = pstack->previous;
	tmp = pstack->previous->previous;
	if (result == tmp)
		return (result);
	while (tmp != pstack->previous)
	{
		if (!((tmp->value / unit) % 10) && !(tmp->value / 10))
			return (tmp);
		if ((tmp->value / unit) % 10 < (result->value / unit) % 10)
			result = tmp;
		tmp = tmp->previous;
	}
	return (result);
}*/

//find best way to rotate
int	count(t_stack *stack, t_stack *pmin)
{
	int	i;
	int	j;
	t_stack	*tmp;

	i = 0;
	j = 0;
	tmp = stack;
	if (stack == pmin)
		return (0);
	while (tmp != pmin)
	{
		i++;
		tmp = tmp->next;
	}
	tmp = stack;
	while (tmp != pmin)
	{
		j++;
		tmp = tmp->previous;
	}
	if (i < j)
		return (i);
	return (-j);
}
//move stack
void	move(t_stack **stack, int count)
{
	if (!stack)
		return ;
	if (count > 0)
	{
		while (count > 0)
		{
			rotate(stack, r_next, "rra");
			count--;
		}
	}
	else
	{
		while (count < 0)
		{
			rotate(stack, r_prev, "ra");
			count++;
		}
	}
}
// move s1 -> s2
void	radix_move(t_stack **s1, t_stack **s2, int size, int unit, char *str)
{
	t_stack	*pstack;
	t_stack	*pmin;
	pstack = *s1;
	while(size > 1)
	{
		pmin = find_min(pstack, unit);
		if (pmin == pstack)
			pstack = pstack->next;
		move(s1, count(*s1, pmin));
		push(s2, s1, str);
		size--;
	}
	push(s2, s1, str);
}

int	find_unit(t_stack *stack)
{
	t_stack	*tmp;
	int	max;
	int	result;
	int	absol;

	result = 0;
	tmp = stack->next;
	if (stack->value < 0)
		max = stack->value * -1;
	while (tmp != stack)
	{
		absol = tmp->value;
		if (absol < 0)
			absol *= -1;
		if (absol > max)
			max = absol;
		tmp = tmp->next;
	}
	while (absol / 10 || absol % 10)
	{
		result++;
		absol = absol / 10;
	}
	return (result);
}

void	radix(t_stack **stack, t_stack **pull, int size)
{
	t_stack	*pstack;
	t_stack	*pmin;
	int	unit;
	int	i;
	int	max;

	max = find_unit(*stack);
	i = 1;
	unit = 1;
	pstack = *stack;

	while (i <= max)
	{
		if (i % 2 != 0)
			radix_move(stack, pull, size, unit, "pa");
		else
			radix_move(pull, stack, size, unit, "pb");
		unit *= 10;
		i++;
	}
	/*
	if (max % 2 != 0)
	{
		while (size > 0)
		{
			rotate(pull, r_prev, "rrb");
			push(stack, pull, "pb");
			size--;
		}
	}*/
}
