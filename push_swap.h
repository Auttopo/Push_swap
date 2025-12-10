/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenabde <abenabde@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:36:11 by abenabde          #+#    #+#             */
/*   Updated: 2025/12/09 09:55:29 by jsam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int value;
	struct s_stack *next;
	struct s_stack *previous;

}	t_stack;

void	swap(char *str);
void	push(t_stack **s1, t_stack **s2);
void	rotate(t_stack **s, int flag);

#endif
