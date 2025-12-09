/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenabde <abenabde@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:35:57 by abenabde          #+#    #+#             */
/*   Updated: 2025/12/08 18:35:57 by abenabde         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ra(t_stack *stack)
{
	t_stack *temp;
	temp = stack->top;


	stack->last->next = stack->top;
	stack->last = stack->top;
	stack->last->next = NULL;
	
	stack->top = stack->top->next;

	stack->top = stack;
	

	write("ra\n");
}
