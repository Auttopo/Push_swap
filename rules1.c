/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsam <jsam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:26:43 by jsam              #+#    #+#             */
/*   Updated: 2025/12/09 14:51:55 by jsam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **s)
{
	t_stack	*tmp;

	if (!*s)
		return ;
	else if (!(*s)->next)
		return ;
	tmp = (*s)->next;
	(*s)->next = (*s)->next->next;
	tmp->next = *s;
	*s = tmp;
}

void	push(t_stack **s1, t_stack **s2)
{
	t_stack	*tmp;
	
	if (!*s1)
		return ;
	tmp = *s1;
	*s1 = (*s1)->next;
	tmp->next = *s2;
	*s2 = tmp;
}

void	rotate(t_stack **s, int flag)
{
	t_stack	*tmp;

	if (!*s)
		return ;
	else if (!(*s)->next)
		return ;
	if (flag > 0)
		*s = (*s)->next;
	else
		*s = (*s)->previous;		
}
