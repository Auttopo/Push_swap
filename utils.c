/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsam <jsam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 19:42:40 by jsam              #+#    #+#             */
/*   Updated: 2026/01/11 16:31:35 by jsam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *nptr)
{
	int	min;
	int	result;

	min = 1;
	result = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			min = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result *= 10;
		result += *nptr - 48;
		nptr++;
	}
	return (result * min);
}
/*
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
*/
/*
void	init_index(t_stack **stack, int size)
{
	t_stack	*tmp;
	t_stack	*result;
	int	i;

	i = 0;
	if (!stack)
		return ;
//	result = stack;
//	tmp = stack->next;
//	if (result == tmp)
//		result->index = 0;
	while (i < size)
	{

		result = (*stack);
		tmp = (*stack)->next;
		while (tmp != (*stack))
		{
			__builtin_printf("%d <  %d\n", tmp->value, result->value);
			if (tmp->value  < result->value && tmp->index == -1)
				result = tmp;
			tmp = tmp->next;
		}
		__builtin_printf(" ------------------- \n");
		result->index = i;
		i++;
	}
}
*/
void    min_indexing(int total, t_stack *local, int x)
{
	t_stack	*temp;
        long    comp;
        int     i;
	int	pos;

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


