/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsam <jsam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:50:29 by jsam              #+#    #+#             */
/*   Updated: 2026/01/12 16:21:45 by jsam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dblswap_checker(t_info *d, t_stack **s1, t_stack **s2)
{
	if (!*s1 || !*s2)
		return ;
	swap(d, s1, "ss");
	swap(d, s2, "\0\0");
}

void	dblrotate_checker(t_info *d, t_stack **s1, t_stack **s2)
{
	if (!*s1 || !*s2)
		return ;
	rotate(d, s1, r_next, "rr");
	rotate(d, s2, r_next, "\0\0");
}

void	dblrrotate_checker(t_info *d, t_stack **s1, t_stack **s2)
{
	if (!*s1 || !*s2)
		return ;
	rotate(d, s1, r_prev, "rrr");
	rotate(d, s2, r_prev, "\0\0");
}

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	while ((i * i) <= nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (i - 1);
}

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
