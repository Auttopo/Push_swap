/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsam <jsam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 19:42:40 by jsam              #+#    #+#             */
/*   Updated: 2026/01/25 14:59:34 by jsam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "checker_bonus.h"

long	ft_atoi(const char *nptr)
{
	long	min;
	long	result;

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
		if (result * min > 2147483647 || result * min < -2147483648)
			return (2147483648);
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

int	free_all(t_stack **s, t_stack **p, char **list, int flag)
{
	int	i;

	i = 0;
	if (flag == 0)
		ft_printf(2, "Error\n");
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

char	**main_init(t_info *d, t_stack **s, t_stack **p)
{
	*s = NULL;
	*p = NULL;
	d->min = 3000000000;
	d->max = -3000000000;
	d->flag = 0;
	return (NULL);
}
