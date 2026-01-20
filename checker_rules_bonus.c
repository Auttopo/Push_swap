/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rules_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenabde <abenabde@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:18:07 by abenabde          #+#    #+#             */
/*   Updated: 2026/01/20 14:48:14 by jsam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include <unistd.h>

void	push_checker(t_stack **dest, t_stack **src)
{
	t_stack	*tmp;

	if (!(*src))
		return ;
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

void	rotate_checker(t_stack **s, void (*move)(t_stack **))
{
	if (!*s || (*s)->next == *s)
		return ;
	move(s);
}

void	r_next(t_stack **s)
{
	*s = (*s)->next;
}

void	r_prev(t_stack **s)
{
	*s = (*s)->previous;
}

void	swap_checker(t_stack **s)
{
	t_stack	*tmp;

	if (!*s || (*s)->next == *s)
		return ;
	if ((*s)->next == (*s)->previous)
	{
		rotate_checker(s, r_next);
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
}
