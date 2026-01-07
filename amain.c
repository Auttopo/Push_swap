
#include <stdio.h> //REMOVE BEFORE THE END PROJECT
#include <unistd.h> // FOR READ
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

char	**free_all(char **list)
{
	int	i;

	i = 0;
	if (list == NULL)
		return (NULL);
	while (list[i] != NULL)
	{
		free(list[i]);
		i++;
	}
	free(list);
	return (NULL);
}

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
	printf("|%d PREV %d IAM %d NEXT|  %d buk\n", (*stack)->previous->value, (*stack)->value, (*stack)->next->value, (*stack)->bucket);
	while (i < max - 1)
	{	
		printf("|%d PREV %d IAM %d NEXT|  %d buk\n", temp->previous->value, temp->value, temp->next->value, temp->bucket);
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
	printf("|%d PREV %d IAM %d NEXT|  %d buk\n", (*stack)->previous->value, (*stack)->value, (*stack)->next->value, (*stack)->bucket);
	while (temp != *stack)
	{	
		printf("|%d PREV %d IAM %d NEXT|  %d buk\n", temp->previous->value, temp->value, temp->next->value, temp->bucket);
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
	nod->bucket = 0;
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

int	arg_checker(char *src)
{
	int	i;
	int	e;
	int temp;

	i = 0;
	e = 0;
	while (src[i])
	{
		while (src[i] == 32 || (src[i] > 8 && src[i] < 14))
			i++;
		temp = i;
		while (src[i] >= '0' && src[i] <= '9')
			i++;
		if (temp != i)
			e++;
		else if (src[i] != '\0')
			return (0);
	}
	return (e);
}

char	*extract_str(char *str, int *i)
{
	char	*new;
	int		e;

	e = *i;
	while (str[e] >= '0' && str[e] <= '9')
		e++;
	new = malloc(sizeof(char) * (e + 1));
	if (new == NULL)
		return (NULL);
	e = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		new[e] = str[*i];
		e++;
		*i += 1;
	}
	new[e] = '\0';
	return (new);
}

char	**arg_parser(char *src, char **list, int *e)
{
	int	i;
	int	size;

	i = 0;
	while (src[i])
	{
		while (src[i] == 32 || (src[i] > 8 && src[i] < 14))
			i++;
		if (src[i] == '\0')
			break ;
		list[*e] = extract_str(src, &i);
		if (list[*e] == NULL)
			return (free_all(list));
		*e += 1;
	}
	return (NULL);
}

int strategy(int flag)
{
	return (flag % 10);
}

int	str_comp(char *str, char *str2)
{
	int	i;

	i = 0;
	while (str[i] == str2[i] && str[i])
		i++;
	if (str[i] != str2[i])
		return (0);
	return (1);
}

int	flag_check(t_flags f, char *str)
{
	if (str_comp(str, f.bench) == 1)
		return (10);
	else if (str_comp(str, f.simple) == 1)
		return (1);
	else if (str_comp(str, f.medium) == 1)
		return (2);
	else if (str_comp(str, f.complex_) == 1)
		return (3);
	return (0);
}

char	**arg_uniformisation(char **str, int max, int i)
{
	int	tmp;
	int	size;
	int	e;
	int	elems;
	char	**list;

	size = 0;
	elems = 0;
	e = i;
	while (i < max)
	{
		tmp = arg_checker(str[i]);
		if (tmp == 0)
			return (0);
		size += tmp;
		i++;
	}
	list = malloc(sizeof(char *) * (size + 1));

	while (e < max)
	{
		arg_parser(str[e], list, &elems);
		e++;
	}
	return (list);
}

int	main(int argc, char **argv)
{
	int		i;
	int		temp;
	int		flg;
	t_stack *stack = NULL;
	t_stack *pull = NULL;
	t_info	data;

	data.min = 3000000000;
	data.max = -3000000000;
	data.total = argc - 1;
	data.currentot = argc - 1;

	data.buk_nbr = ((float)ft_sqrt(data.total) * (float)0.6);

	flg = 0;
	t_flags	f;
	f.bench = "--bench";
	f.simple = "--simple";
	f.medium = "--medium";
	f.complex_ = "--complex";

	
	if (argc < 2)
		return (0);
	i = 1;

	while (i < (argc - 1) && (i < 3))
	{
		temp = flag_check(f, argv[i]);
		if ((flg % 10) == 0 || temp > 9)
			flg += temp;
		i++;
	}
	if (temp == 0)
		i--;

	char **list = arg_uniformisation(argv, argc, i);
	

	if (list == NULL)
		return (0);
/*
	i = 0;
	while (list[i] != NULL)
	{
		printf("%s\n", list[i]);
		i++;
	}

	printf("---%d flg\n", flg);
*/

/*

	int flag;
	int flag1 = flag_reader(argv[1]);
	int flag2;
	if (argc > 3)
	{
		flag2 = flag_reader(argv[2]):
	}
	flag = flag1 + flag2;
	10 for bench
	1 simple
	2 medium
	3 complex
	0 adaptative




*/



	i = 0;
	while (list[i])
	{
		temp = add_back_nod(&stack, new_elem(ft_atoi(list[i])));
		if (data.max < (long)temp)
			data.max = (long)temp;
		else if (data.min > (long)temp)
			data.min = (long)temp;
		i++;
	}





	show_stack(&stack);
	show_stack(&pull);




	if (strategy(flg) == 1)
	{
		selection(data.total, &stack, &pull);
	}
	else if (strategy(flg) == 2)
	{
		buckets(&data, &stack, &pull);
	}
	else if (strategy(flg) == 3)
	{
		printf("radix not implemented\n");
	}
	else
	{
		printf("need optimisation\n");
	}



//	show_stack(&stack);
//	show_stack(&pull);

//	buckets(&data, &stack, &pull);
//	value_sorter(data, &stack, &pull);

	show_stack(&stack);
	show_stack(&pull);

	free_all(list);
	clear_list(&stack);
	clear_list(&pull);
}
