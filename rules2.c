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

#include "push_swap.h"

void	dblswap(t_stack **s1, t_stack **s2)
{
	if (!*s1 || !*s2)
		return ;
	swap(s1, "ss");
	swap(s2, 0);
}

void	dblrotate(t_stack **s1, t_stack **s2)
{
	if (!*s1 || !*s2)
		return ;
	rotate(s1, r_next, "ra");
	rotate(s2, r_next, "rb");
}

void	dblrrotate(t_stack **s1, t_stack **s2)
{
	if (!*s1 || !*s2)
		return ;
	rotate(s1, r_prev, "ra");
	rotate(s2, r_prev, "rrb");
}
