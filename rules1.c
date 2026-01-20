/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsam <jsam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:26:43 by jsam              #+#    #+#             */
/*   Updated: 2026/01/18 18:44:24 by jsam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	push(t_info *d, t_stack **dest, t_stack **src, char *str)
{
	t_stack	*tmp;

	if (!(*src))
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

/*
void	dblswap(t_info *d, t_stack **s1, t_stack **s2)
{
	if (!*s1 || !*s2)
		return ;
	swap(d, s1, "ss");
	swap(d, s2, "\0\0");
}

void	dblrotate(t_info *d, t_stack **s1, t_stack **s2)
{
	if (!*s1 || !*s2)
		return ;
	rotate(d, s1, r_next, "rr");
	rotate(d, s2, r_next, "\0\0");
}

void	dblrrotate(t_info *d, t_stack **s1, t_stack **s2)
{
	if (!*s1 || !*s2)
		return ;
	rotate(d, s1, r_prev, "rrr");
	rotate(d, s2, r_prev, "\0\0");
}
*/
