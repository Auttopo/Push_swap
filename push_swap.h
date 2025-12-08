/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenabde <abenabde@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:36:11 by abenabde          #+#    #+#             */
/*   Updated: 2025/12/08 18:36:13 by abenabde         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_stack
{
	int value;
	t_stack *top;
	t_stack *next;
	t_stack *last;

}	t_stack;
