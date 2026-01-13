/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenabde <abenabde@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 10:53:57 by abenabde          #+#    #+#             */
/*   Updated: 2026/01/13 10:53:57 by abenabde         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void	init_list(t_stack **stack, t_stack *new)
{
	*stack = new;
	(*stack)->next = *stack;
	(*stack)->previous = *stack;
}

t_stack	*add_back_nod(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	if (new == NULL)
		return (NULL);
	if (*stack == NULL)
	{
		init_list(stack, new);
		return (new);
	}

	temp = *stack;
	while (temp->next != *stack)
		temp = temp->next;
	new->next = *stack;
	new->previous = temp;
	temp->next = new;
	(*stack)->previous = new;
	return (new);
}

t_stack	*new_elem(int value)
{
	t_stack	*nod;
	nod = malloc(sizeof(t_stack));
	if (nod == NULL)
		return (NULL);
	nod->index = -1;
	nod->value = value;
	nod->bucket = 0;
	return (nod);
}

/*
int	add_front_nod(t_stack **stack, t_stack *new)
{
	t_stack	*temp;


	if (new == NULL)
		return (0);
	if (*stack == NULL)
	{
		init_list(stack, new);
		return (1);
	}

	new->next = *stack;
	new->previous = (*stack)->previous;
	(*stack)->previous = new;
	new->previous->next = new;

	*stack = new;
	return (1);
}
*/
