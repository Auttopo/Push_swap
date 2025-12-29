
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

void	show_bugs(t_stack **stack, int max)
{
	t_stack	*temp;
	int	i;

	if (*stack == NULL)
	{
		printf("no stack\n\n");
		return ;
	}

	i = 0;
	temp = (*stack)->next;
//	printf("|%d|\n", (*stack)->value);
	printf("|%dPREV %dIAM %dNEXT|\n", (*stack)->previous->value, (*stack)->value, (*stack)->next->value);
	while (i < max - 1)
	{	
		printf("|%dPREV %dIAM %dNEXT|\n", temp->previous->value, temp->value, temp->next->value);
//		printf("|%d|\n", temp->value);
		temp = temp->next;
		i++;
	}
	printf("\n");
}


void	show_stack(t_stack **stack)
{
	t_stack	*temp;

	if (*stack == NULL)
	{
		printf("no stack\n\n");
		return ;
	}

	temp = (*stack)->next;
//	printf("|%d|\n", (*stack)->value);
	printf("|%dPREV %dIAM %dNEXT|\n", (*stack)->previous->value, (*stack)->value, (*stack)->next->value);
	while (temp != *stack)
	{	
		printf("|%dPREV %dIAM %dNEXT|\n", temp->previous->value, temp->value, temp->next->value);
//		printf("|%d|\n", temp->value);
		temp = temp->next;
	}
	printf("\n");
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
	if (*stack == NULL)
	{
		init_list(stack, new);
		return (1);
	}

	temp = *stack;
	while (temp->next != *stack)
		temp = temp->next;
	new->next = *stack;
	new->previous = temp;
	temp->next = new;
	(*stack)->previous = new;
	return (1);
}

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

	if (*stack == NULL)
		return ;
	(*stack)->previous->next = NULL;
	while (*stack != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	t_stack *stack = NULL;
	t_stack *pull = NULL;

	i = 1;
	while (i <= argc)
	{
		add_front_nod(&stack, new_elem(5));
		
	}

	// STACK ONE -------------------------------------//
/*	
	t_stack fake;
	fake.value = 99;

	t_stack *last_pt = &fake;
*/

//	t_stack *stack = malloc(sizeof(t_stack));

/*	t_stack *data = NULL;
	t_stack *sort = NULL;
	t_stack **stack = &data;
	t_stack **pull = &sort;
*/

//	stack->value = 1;
//	stack->next = NULL;

	add_front_nod(&stack, new_elem(5));
	add_front_nod(&stack, new_elem(4));
	add_front_nod(&stack, new_elem(3));
	add_front_nod(&stack, new_elem(2));
	add_front_nod(&stack, new_elem(1));
//	add_front_nod(&stack, new_elem(0));

	

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

	
//	show_bugs(&stack, 1);

//	show_stack(&stack);
//	show_stack(&pull);
	
	selection(5, &stack, &pull);
/*	push(&pull, &stack, "-------\n");
	push(&pull, &stack, "-------\n");
	push(&pull, &stack, "-------\n");
	push(&pull, &stack, "-------\n");
*/
//	printf("RESULT:stack\n");
//	show_stack(&stack);
//	printf("RESULT:pull\n");
//	show_stack(&pull);


//	show_stack(&stack);
//	show_stack(&pull);
	
//	swap(&stack, "ss");
//	bubble(&stack, 7);		
//	show_stack(&stack);

/*
	show_stack(stack);
	printf("SWAP\n\n");
	show_stack(stack);		
	printf("PUSH\n\n");
	push(&stack, &stack2);
//	push(&pull, &stack, "-------\n");
	show_stack(stack);		
	show_stack(stack2);		
*/










	clear_list(&stack);
	clear_list(&pull);


}
