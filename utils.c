/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsam <jsam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 19:42:40 by jsam              #+#    #+#             */
/*   Updated: 2026/01/13 11:41:59 by abenabde         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
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

void	clear_stack(t_stack **stack)
{
	t_stack	*temp;

	if (*stack == NULL)
		return ;
	(*stack)->previous->next = NULL;
	while (*stack != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

int	free_all(t_stack **s, t_stack **p, char **list)
{
	int	i;

	i = 0;
	if (list == NULL)
		return (0);
	while (list[i] != NULL)
	{
		free(list[i]);
		i++;
	}
	free(list);
	clear_stack(s);
	clear_stack(p);
	return (0);
}

void	main_init(t_info *d, t_flags *f, t_stack **s, t_stack **p)
{
	d->sa = 0;
	d->sb = 0;
	d->ss = 0;
	d->pa = 0;
	d->pb = 0;
	d->ra = 0;
	d->rb = 0;
	d->rr = 0;
	d->rra = 0;
	d->rrb = 0;
	d->rrr = 0;


	*s = NULL;
	*p = NULL;

	d->min = 3000000000;
	d->max = -3000000000;
	d->flag = 0;
	f->bench = "--bench";
	f->simple = "--simple";
	f->medium = "--medium";
	f->complex_ = "--complex";
	f->adaptative = "--adaptative";

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
