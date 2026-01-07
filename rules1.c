/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsam <jsam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:26:43 by jsam              #+#    #+#             */
/*   Updated: 2026/01/06 19:06:10 by jsam             ###   ########lyon.fr   */
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

void	push(t_stack **dest, t_stack **src, char *str)
{
	t_stack	*tmp;
	
	if (*src == NULL)
		return ;
	ft_putstr(str);

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

void	rotate(t_stack **s, void (*move)(t_stack **), char *str)
{
	if (!*s)
		return ;
	move(s);
	if (str)
		ft_putstr(str);
}

void	swap(t_stack **s, char *str)
{
	t_stack	*tmp;

	if (!*s)
		return ;
	else if (!(*s)->next)
		return ;

	if ((*s)->next == (*s)->previous)
	{
		rotate(s, r_next, str);
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

	ft_putstr(str);
}



