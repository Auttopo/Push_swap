/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenabde <abenabde@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 20:30:19 by abenabde          #+#    #+#             */
/*   Updated: 2025/12/08 20:30:19 by abenabde         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //REMOVE BEFORE THE END PROJECT
#include "push_swap.h"

// TESTS Functions
void	show_stack(t_nod *nod)
{
	if (*nod == NULL)
		return ;
	printf("|%d|\n", *nod->value);
	show_stack(nod->next);
}

void	add_nod(t_nod **lst, t_nod *new)
{
	new->next = *lst;
	*lst = new;
}

t_nod	new_elem(int value)
{
	t_nod	nod;
	nod->value = value;
	return (nod);
}

t_nod	last_nod(t_nod *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

int	main()
{
	s_stack stack;
	s_nod nod;
	


	add_nod(nod, new_elem(6));
	add_nod(nod, new_elem(2));
	add_nod(nod, new_elem(4));
	add_nod(nod, new_elem(6));
	add_nod(nod, new_elem(9));
	add_nod(nod, new_elem(1));
	add_nod(nod, new_elem(7));
	add_nod(nod, new_elem(3));

	stack->top = nod;
	stack->last = last_nod(&nod);

	show_stack(stack->nod);		



}
