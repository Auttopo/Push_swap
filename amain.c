/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   amain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenabde <abenabde@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 20:30:19 by abenabde          #+#    #+#             */
/*   Updated: 2025/12/10 15:59:29 by jsam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //REMOVE BEFORE THE END PROJECT
#include "push_swap.h"
#include <stdlib.h>
// TESTS Functions/
/*
t_stack	*last_nod(t_stack *stack)
{
	if (stack == NULL)
		return NULL;
	while (stack->next != NULL)
	{
		stack = stack->next;
	}
	return (stack);
}
*/

t_stack	*get_nodx(t_stack **stack, int n)
{
	// NON TESTER --!
	int	i;
	t_stack	*temp;

	i = 0;
	temp = *stack;
	while (temp->next != *stack || i < n)
	{
		temp = temp->next;
		i++;
	}
	return (temp);
}

void	show_stack(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	printf("|%d|\n", temp->value);
	while (temp->next != *stack)
	{
		temp = temp->next;
		printf("|%d|\n", temp->value);
	}
}

void	init_list(t_stack **stack, t_stack *new)
{
	*stack = new;
	(*stack)->next = *stack;
	(*stack)->previous = *stack;
}

int	add_back_nod(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	if (new == NULL)
		return (0);
	temp = *stack;
	while (temp->next != *stack)
		temp = temp->next;
	new->next = *stack;
	new->previous = temp;
	temp->next = new;
	(*stack)->previous = new;
	return (1);
}

t_stack	*new_elem(int value)
{
	t_stack	*nod;
	nod = malloc(sizeof(t_stack));
	if (nod == NULL)
		return (NULL);

	nod->value = value;
	return (nod);
}

void	clear_list(t_stack **stack)
{
	t_stack	*temp;

	(*stack)->previous->next = NULL;
	while (*stack != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

int	main()
{

	// STACK ONE -------------------------------------//
/*	
	t_stack fake;
	fake.value = 99;

	t_stack *last_pt = &fake;
*/

//	t_stack *stack = malloc(sizeof(t_stack));
	t_stack *stack = NULL;
	t_stack *pull = NULL;
/*	t_stack *data = NULL;
	t_stack *sort = NULL;
	t_stack **stack = &data;
	t_stack **pull = &sort;
*/

//	stack->value = 1;
//	stack->next = NULL;

	init_list(&stack, new_elem(6));
	add_back_nod(&stack, new_elem(2));
	add_back_nod(&stack, new_elem(4));
	add_back_nod(&stack, new_elem(6));
	add_back_nod(&stack, new_elem(9));
	add_back_nod(&stack, new_elem(7));
	add_back_nod(&stack, new_elem(3));

	show_stack(&stack);		
	

//	selection(&stack, &pull);


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

//	rotate(stack);
//	show_stack(stack);	
	bubble(&stack, 7);		

	show_stack(stack);		

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
