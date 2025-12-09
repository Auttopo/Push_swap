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


typedef struct s_nod
{
	int value;
	t_nod *next;

}	t_nod;

typedef struct s_stack
{
	t_nod	*top;
	t_nod	*last;

}	t_stack;
