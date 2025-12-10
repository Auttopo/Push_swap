/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsam <jsam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:26:43 by jsam              #+#    #+#             */
/*   Updated: 2025/12/10 10:43:31 by jsam             ###   ########lyon.fr   */
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

	if (!*s)
		return ;
	else if (!(*s)->next)
		return ;
	tmp = (*s)->next;
	(*s)->next = (*s)->next->next;
	tmp->next = *s;
	*s = tmp;
	if (str)
		ft_putstr(str);
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

<<<<<<< HEAD
/*
int	main()

void	rotate(t_stack **s, int flag)
=======
void	rotate(t_stack **s, int flag, char *str)
>>>>>>> origin/main
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
	if (str)
		ft_putstr(str);
}
*/
