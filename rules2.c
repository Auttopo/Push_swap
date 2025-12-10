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
#include "push_swap.h"

void	rotate(t_stack *stack)
{
	(*(stack->last))->next = stack;
	(*(stack->last)) = stack;
	(*(stack->last))->next = NULL;
	
	stack = stack->next;
}
