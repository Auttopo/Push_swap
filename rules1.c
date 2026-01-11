/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsam <jsam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:26:43 by jsam              #+#    #+#             */
/*   Updated: 2026/01/09 16:28:09 by jsam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include "ft_printf/ft_printf.h"

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

static void	putstr_log(t_info *d, char *s)
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

void	push(t_info *d, t_stack **dest, t_stack **src, char *str)
{
	t_stack	*tmp;
	
	if (*src == NULL)
		return ;
	putstr_log(d, str);

	if ((*src)->next == *src)
		tmp = NULL;
	else
		tmp = (*src)->next;

	(*src)->previous->next = (*src)->next;
	(*src)->next->previous = (*src)->previous;

	if (*dest == NULL)
	{
		*dest = *src;
		(*src)->next = *src;
		(*src)->previous = *src;

		*src = tmp;

		return ;
	}

	(*src)->next = *dest;
	(*src)->previous = (*dest)->previous;


	(*dest)->previous->next = *src;
	(*dest)->previous = *src;

	*dest = *src;
	*src = tmp;
}

void	r_next(t_stack **s)
{
	*s = (*s)->next;
}

void	r_prev(t_stack **s)
{
	*s = (*s)->previous;
}

void	rotate(t_info *d, t_stack **s, void (*move)(t_stack **), char *str)
{
	if (!*s)
		return ;
	move(s);
	if (str)
		putstr_log(d, str);
}

void	swap(t_info *d, t_stack **s, char *str)
{
	t_stack	*tmp;

	if (!*s)
		return ;
	else if (!(*s)->next)
		return ;

	if ((*s)->next == (*s)->previous)
	{
		rotate(d, s, r_next, str);
		return ;
	}

	tmp = (*s)->next->next;
	(*s)->next->previous = (*s)->previous;
	(*s)->next = tmp;
	(*s)->previous->next = tmp->previous;
	(*s)->previous = tmp->previous;
	tmp->previous->next = *s;
	*s = tmp->previous;	
		
	(*s)->next->next->previous = (*s)->next;

	putstr_log(d, str);
}

void	bench_mod(t_info d, float disorder, int strat)
{
	char	*strategy;
	int		total;

	total = d.sa + d.sb + d.ss + d.pa + d.pb + d.ra + d.rb + d.rr + d.rra + d.rrb + d.rrr;
	if (strat == 1)
		strategy = "Simple / (O(n²))";
	else if (strat == 2)
		strategy = "Medium / (O(n√n))";
	else
		strategy = "Complex / (O(n log n))";

	ft_printf("[BENCH MOD]\n\ndisorder: %d%%\n", (int)(disorder * 100));
	ft_printf("strategy: %s\n", strategy);
	ft_printf("total operations: %d\n", total);
	ft_printf("sa: %d | sb: %d | ss: %d | pa: %d | pb: %d\n", d.sa ,d.sb ,d.ss ,d.pa ,d.pb);
	ft_printf("ra: %d | rb: %d | rr: %d | rra: %d | rrb: %d | rrr: %d\n", d.ra, d.rb, d.rr, d.rra, d.rrb, d.rrr);

}
