/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsam <jsam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:23:47 by jsam              #+#    #+#             */
/*   Updated: 2026/01/06 17:53:20 by jsam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> // DELETE BEFORE PUSH

//return ptr node min for one unit (if unit == 1 then find min (value / 1) % 10. if unit == 10 then find min (value/10) % 10)
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
		/*if (((tmp->value / unit) % 10) * min_max > ((result->value / unit) % 10) * min_max)
			result = tmp;
		tmp = tmp->next;*/
		if (((tmp->index / unit) % 10) * min_max > ((result->index / unit) % 10) * min_max)
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
void	rotate_stack(t_stack **stack, int count, int rstack)
{
	char	*str;

	str = "error";
	if (rstack == 1 && count > 0)
		str = "ra";
	else if (rstack == 1 && count < 0)
		str = "rra";
	else if (rstack == 2 && count > 0)
		str = "rb";
	else if (rstack == 2 && count < 0)
		str = "rrb";
	if (!stack)
		return ;
	if (count > 0)
	{
		while (count > 0)
		{
			rotate(stack, r_next, str);
			count--;
		}
	}
	else if (count < 0)
	{
		while (count < 0)
		{
			rotate(stack, r_prev, str);
			count++;
		}
	}
}
// move s1 -> s2
void	radix_move(t_stack **s1, t_stack **s2, int size, int unit, char *pushstr, int min_max, int rotate)
{
	t_stack	*pstack;
	t_stack	*pmin;
	pstack = *s1;
	while(size > 1)
	{
		pmin = find_minmax(pstack, unit, min_max);
		if (pmin == pstack)
			pstack = pstack->next;
		rotate_stack(s1, count(*s1, pmin), rotate);
		push(s2, s1, pushstr);
		size--;
	}
	push(s2, s1, pushstr);
}

int	find_unit(t_stack *stack)
{
	t_stack	*tmp;
	int	max;
	int	result;
	int	absol;

	result = 1;
	max = stack->index;
	tmp = stack->next;
/*	if (stack->value < 0)
		max = stack->value * -1;*/
	while (tmp != stack)
	{
		absol = tmp->index;
		/*if (absol < 0)
			absol *= -1;*/
		if (absol > max)
			max = absol;
		tmp = tmp->next;
	}
	while (max / 10 || max % 10)
	{
		result++;
		max = max / 10;
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

	i = 1;
	unit = 1;
	pstack = *stack;
	init_index(*stack, size);
	max = find_unit(*stack);
	while (i <= max)
	{
		if (i % 2 != 0)
			radix_move(stack, pull, size, unit, "pb", -1, 1);
		else
			radix_move(pull, stack, size, unit, "pa", 1, 2);
		unit *= 10;
		i++;
	}
	if (!(*stack))
	{
		while (size > 0)
		{
			push(stack, pull, "pa");
			size--;
		}
	}
}
