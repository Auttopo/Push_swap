/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsam <jsam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:26:43 by jsam              #+#    #+#             */
/*   Updated: 2025/12/28 15:21:22 by jsam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	write (1, "\n", 1);
}

void	swap(t_stack **s, char *str)
{
//	t_stack	*tmp1;
//	t_stack	*tmp2;
	t_stack	*tmp;

	int	temp;

	if (!*s)
		return ;
	else if (!(*s)->next)
		return ;
/*
	tmp1 = *s;
	tmp2 = (*s)->next->next;
	*s = (*s)->next;
	(*s)->previous = tmp1->previous;
	(*s)->next = tmp1;
	tmp1->next = tmp2;
	tmp1->previous = *s;
*/
	tmp = (*s)->next->next;
	(*s)->next->previous = (*s)->previous;
	(*s)->next = tmp;
	(*s)->previous->next = tmp->previous;
	(*s)->previous = tmp->previous;
	tmp->previous->next = *s;
	*s = tmp->previous;	


		
}

void	push(t_stack **s1, t_stack **s2, char *str)
{
	t_stack	*tmp;
	
	if (!*s1)
		return ;
	tmp = *s1;
	*s1 = (*s1)->next;
	tmp->next = *s2;
	*s2 = tmp;
	if (str)
		ft_putstr(str);
}

void	r_next(t_stack **s)
{
	*s = (*s)->next;
}

void	r_prev(t_stack **s)
{
	*s = (*s)->previous;
}

void	rotate(t_stack **s, void (*move)(t_stack **), char *str)
{
	if (!*s)
		return ;
	move(s);
	if (str)
		ft_putstr(str);
}



