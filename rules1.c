/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsam <jsam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:26:43 by jsam              #+#    #+#             */
/*   Updated: 2025/12/09 11:55:37 by jsam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **s)
{
	t_stack	*tmp;

	tmp = (*s)->next;
	(*s)->next = (*s)->next->next;
	tmp->next = *s;
	*s = tmp;
}

void	push(t_stack **s1, t_stack **s2)
{
	t_stack	*tmp;

	tmp = *s1;
	*s1 = (*s1)->next;
	tmp->next = *s2;
	*s2 = tmp;
}
/*
int	main()
{
	t_stack	*pt1;
	t_stack	test01;
	t_stack	test02;
	t_stack	*pt2;
	t_stack	testA;
	t_stack	testB;

	test01.next = &test02;
	test01.value = 10;
	test02.next = 0;
	test02.value = 20;
	pt1 = &test01;
	testA.next = &testB;
	testA.value = 100;
	testB.next = 0;
	testB.value = 200;
	pt2 = &testA;

	push(&pt1, &pt2);

	return (0);
}
*/
