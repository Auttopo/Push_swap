/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsam <jsam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:26:43 by jsam              #+#    #+#             */
/*   Updated: 2025/12/28 19:18:29 by jsam             ###   ########lyon.fr   */
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
	t_stack	*tmp;
	t_stack	*data;

	if (!*s)
		return ;
	else if (!(*s)->next)
		return ;

	t_stack *data = (*s)->next;

	tmp = (*s)->next->next;
	(*s)->next->next = (*s)->next;
	(*s)->next = tmp;

	tmp = (*s)->next->previous;
	(*s)->next->previous = (*s)->previous;
	(*s)->previous = tmp;

	*s = data;
	
	(*s)->previous->next = data
	(*s)->next->next->previous = (*s)->next;
		
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



