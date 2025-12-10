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
#include <stdlib.h>

// TESTS Functions/

t_stack	*get_nodx(t_stack *stack, int n)
{
	int i = 0;
	while(i < n - 1 && stack->next != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (stack);
}

void	show_last(t_stack *stack)
{
	if (stack == NULL)
	{
		printf("\n\n");
		return ;
	}
	printf("|%p| |%d|\n", stack->last, (*stack->last)->value);
	show_last(stack->next);
}


void	show_stack(t_stack *stack)
{
	if (stack == NULL)
	{
		printf("\n\n");
		return ;
	}
	printf("|%d|\n", stack->value);
	show_stack(stack->next);
}

void	add_back_nod(t_stack **lst, t_stack *new)
{
	if (*lst == NULL)
	{
	//	*(lst->last) = new;
		*lst = new;
		return ;
	}
	if ((*lst)->next == NULL)
	{
	//	*(lst->last) = new;
		(*lst)->next = new;
		return ;
	}
	add_back_nod(&(*lst)->next, new);
}

void	add_front_nod(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}

t_stack	*new_elem(t_stack stack, int value)
{
	t_stack	*nod;
	nod = malloc(sizeof(t_stack));
	if (nod == NULL)
		return (NULL);

	nod->value = value;
	nod->next = NULL;
	return (nod);
}

t_stack	*last_nod(t_stack *lst)
{
	if (lst == NULL)
		return NULL;
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	clear_list(t_stack **stack)
{
	if (*stack == NULL)
		return ;
	t_stack *temp;
	temp = (*stack)->next;
	free(*stack);
	clear_list(&temp);
}

int	main()
{

	// STACK ONE -------------------------------------//
/*	
	t_stack fake;
	fake.value = 99;

	t_stack *last_pt = &fake;
*/

	//t_stack *stack = malloc(sizeof(t_stack));
	t_stack *stack = NULL;
/*	stack->last = &last_pt;
	stack->value = 1;
	stack->next = NULL;*/

	add_back_nod(&stack, new_elem(*stack, 6));
/*	add_back_nod(&stack, new_elem(*stack, 2));
	add_back_nod(&stack, new_elem(*stack, 4));
	add_back_nod(&stack, new_elem(*stack, 6));
	add_back_nod(&stack, new_elem(*stack, 9));
	add_back_nod(&stack, new_elem(*stack, 7));
	add_back_nod(&stack, new_elem(*stack, 3));*/

	// STACK TWO -----------------------------------------//

/*	t_stack *stack2 = malloc(sizeof(t_stack));
	stack2->last = &stack2;
	*(stack2->last) = stack2;
	stack2->value = 0;
	stack2->next = NULL;

	add_back_nod(&stack2, new_elem(*stack2, 0));
	add_back_nod(&stack2, new_elem(*stack2, 0));
	add_back_nod(&stack2, new_elem(*stack2, 0));
	add_back_nod(&stack2, new_elem(*stack2, 0));
	add_back_nod(&stack2, new_elem(*stack2, 0));
	add_back_nod(&stack2, new_elem(*stack2, 0));
	add_back_nod(&stack2, new_elem(*stack2, 0));
*/

	// LAST TESTS ------------------------------------------------//	
	/*t_stack *last = last_nod(stack);
	(*stack->last) = get_nodx(stack, 3);
	show_stack(stack);	
	show_last(stack);*/

//--------------------------------------------------------//

/*	show_stack(stack);		
	rotate(stack);
	show_stack(stack);		
*/

/*
	show_stack(stack);
	printf("SWAP\n\n");
	swap(&stack);
	show_stack(stack);		
	printf("PUSH\n\n");
	push(&stack, &stack2);
	show_stack(stack);		
	show_stack(stack2);		
*/










	clear_list(&stack);
//	clear_list(&stack2);


}
