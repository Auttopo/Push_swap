
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
	return (new->value);
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
	int		i;
	int		temp;
	t_stack *stack = NULL;
	t_stack *pull = NULL;
	t_info	data;

	data.min = 3000000000;
	data.max = -3000000000;
	data.total = argc - 1;
	if (argc < 2)
		return (0);
	i = 1;
	while (i < argc)
	{
		temp = add_back_nod(&stack, new_elem(ft_atoi(argv[i])));
		if (data.max < (long)temp)
			data.max = (long)temp;
		else if (data.min > (long)temp)
			data.min = (long)temp;
		i++;
	}
//	selection(data.total, &stack, &pull);
	buckets(data, &stack, &pull);

	show_stack(&stack);
	printf("-----------------\n");
	show_stack(&pull);

	clear_list(&stack);
	clear_list(&pull);
}
