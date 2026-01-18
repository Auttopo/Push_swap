/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenabde <abenabde@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:13:10 by abenabde          #+#    #+#             */
/*   Updated: 2026/01/15 15:31:32 by jsam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

static void	r_case(t_info *d, char *s)
{
	if (s[1] == 'a')
		d->ra += 1;
	else if (s[1] == 'b')
		d->rb += 1;
	else if (s[2] == 'a')
		d->rra += 1;
	else if (s[2] == 'b')
		d->rrb += 1;
	else if (s[2] == 'r')
		d->rrr += 1;
	else
		d->rr += 1;
}

static void	put_in_log(t_info *d, char *s)
{
	if (s[0] == 'p')
	{
		if (s[1] == 'a')
			d->pa += 1;
		else
			d->pb += 1;
	}
	else if (s[0] == 'r')
		r_case(d, s);
	else
	{
		if (s[1] == 'a')
			d->sa += 1;
		else if (s[1] == 'b')
			d->sb += 1;
		else
			d->ss += 1;
	}
}

void	putstr_log(t_info *d, char *s)
{
	int	i;

	i = 0;
	put_in_log(d, s);
	if (d->flag > 9)
		return ;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	write (1, "\n", 1);
}

void	bench_mod(t_info d, float disorder, int strat)
{
	char	*strategy;
	int		total;

	if (d.flag < 10)
		return ;
	total = d.sa + d.sb + d.ss + d.pa + d.pb
		+ d.ra + d.rb + d.rr + d.rra + d.rrb + d.rrr;
	if (strat == 3)
		strategy = "Complex / (O(n log n))";
	else if (strat == 2)
		strategy = "Medium / (O(n√n))";
	else
		strategy = "Simple / (O(n²))";
	ft_printf(2, "[BENCH MOD]\n\ndisorder: %d,%d%%\n",
		(int)(disorder * 100), ((int)(disorder * 10000) % 100));
	ft_printf(2, "strategy: %s\n", strategy);
	ft_printf(2, "total operations: %d\n", total);
	ft_printf(2, "sa: %d | sb: %d | ss: %d | pa: %d | pb: %d\n",
		d.sa, d.sb, d.ss, d.pa, d.pb);
	ft_printf(2, "ra: %d | rb: %d | rr: %d | rra: %d | rrb: %d | rrr: %d\n",
		d.ra, d.rb, d.rr, d.rra, d.rrb, d.rrr);
}
