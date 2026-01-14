/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rules1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsam <jsam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:19:13 by jsam              #+#    #+#             */
/*   Updated: 2026/01/14 11:26:36 by jsam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	push_checker(t_info *d, t_stack **dest, t_stack **src)
{
	t_stack	*tmp;

	if (*src == NULL)
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

void	rotate_checker(t_info *d, t_stack **s, void (*move)(t_stack **))
{
	if (!*s)
		return ;
		move(s);
}
void	swap_checker(t_info *d, t_stack **s)
{
	t_stack	*tmp;

	if (!*s)
		return ;
	else if (!(*s)->next)
		return ;

	if ((*s)->next == (*s)->previous)
	{
		rotate_checker(d, s, r_next);
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

