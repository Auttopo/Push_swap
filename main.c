#include <stdio.h> //REMOVE BEFORE THE END PROJECT
#include <unistd.h> // FOR READ
#include "push_swap.h"
#include <stdlib.h>

void	clear_stack(t_stack **stack)
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

int	free_all(t_stack **s, t_stack **p, char **list)
{
	int	i;

	i = 0;
	if (list == NULL)
		return (0);
	while (list[i] != NULL)
	{
		free(list[i]);
		i++;
	}
	free(list);
	clear_stack(s);
	clear_stack(p);
	return (0);
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
	printf("|%d PREV %d IAM %d NEXT|  %d buk\n", (*stack)->previous->value, (*stack)->value, (*stack)->next->value, (*stack)->bucket);
	while (temp != *stack)
	{	
		printf("|%d PREV %d IAM %d NEXT|  %d buk\n", temp->previous->value, temp->value, temp->next->value, temp->bucket);
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

t_stack	*add_back_nod(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	if (new == NULL)
		return (NULL);
	if (*stack == NULL)
	{
		init_list(stack, new);
		return (new);
	}

	temp = *stack;
	while (temp->next != *stack)
		temp = temp->next;
	new->next = *stack;
	new->previous = temp;
	temp->next = new;
	(*stack)->previous = new;
	return (new);
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
	nod->index = -1;
	nod->value = value;
	nod->bucket = 0;
	return (nod);
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
		while ((src[i] == 32) || ((src[i] > 8) && (src[i] < 14)))
			i++;
		temp = i;
		if (src[i] == '-')
			i++;
		while (src[i] >= '0' && src[i] <= '9')
			i++;
		if (temp != i)
			e++;
		else if (src[i] != '\0')
			return (0);
		if (src[i - 1] == '-')
			return (0);
	}
	return (e);
}

char	*extract_str(char *str, int *i)
{
	char	*new;
	int		e;

	e = *i;

	if (str[e] == '-')
		e++;
	while (str[e] >= '0' && str[e] <= '9')
		e++;
	new = malloc(sizeof(char) * (e + 1));
	if (new == NULL)
		return (NULL);
	e = 0;
	while (str[*i] >= '0' && str[*i] <= '9' || str[*i] == '-')
	{
		new[e] = str[*i];
		e++;
		*i += 1;
	}
	new[e] = '\0';
	return (new);
}

int	arg_parser(char *src, char **list, int *e)
{
	int	i;
	int	size;

	i = 0;
	while (src[i])
	{
		while ((src[i] == 32) || ((src[i] > 8) && (src[i] < 14)))
			i++;
		if (src[i] == '\0')
			break ;
		list[*e] = extract_str(src, &i);
		if (list[*e] == NULL)
			return (0);
		*e += 1;
	}
	return (1);
}

int mod(int flag)
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
	else if (str_comp(str, f.adaptative) == 1)
		return (4);
	return (0);
}

int	arg_uniformisation(char ***list, char **str, int max, int i)
{
	int	tmp;
	int	e;
	int	elems;

	e = i;
	elems = 0;
	while (i < max)
	{
		tmp = arg_checker(str[i]);
		if (tmp == 0)
			return (0);
		elems += tmp;
		i++;
	}
	*list = malloc(sizeof(char *) * (elems + 1));
	if (*list == NULL)
		return (0);
	elems = 0;
	while (e < max)
	{
		if (arg_parser(str[e], *list, &elems) == 0)
			return (0);
		e++;
	}
	return (1);
}

int	verif_dbl(char **list)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = 0;
	while (list[size])
		size++;
	while (i < size)
	{
		j = i + 1;
		while (list[j])
		{
			if (str_comp(list[i], list[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	main_init(t_info *d, t_flags *f, t_stack *s, t_stack *p)
{
	d->sa = 0;
	d->sb = 0;
	d->ss = 0;
	d->pa = 0;
	d->pb = 0;
	d->ra = 0;
	d->rb = 0;
	d->rr = 0;
	d->rra = 0;
	d->rrb = 0;
	d->rrr = 0;


	s = NULL;
	p = NULL;

	d->min = 3000000000;
	d->max = -3000000000;
	d->flag = 0;
	f->bench = "--bench";
	f->simple = "--simple";
	f->medium = "--medium";
	f->complex_ = "--complex";
	f->adaptative = "--adaptative";
	
}

int	main(int argc, char **argv)
{
	int		i;
	int		temp;
	int		flg;
	float	disorder;
	char	**list;
	t_flags	f;
	t_info	data;
	t_stack	*stack;
	t_stack	*pull;
	t_stack	*stk_tmp;

	list = NULL;
	i = 1;
	main_init(&data, &f, stack, pull);
	
	if (argc < 2)
		return (0);

	while (i < (argc - 1) && (i < 3) &&  argv[i][1] == '-')
	{
		temp = flag_check(f, argv[i]);
		if ((mod(data.flag) && mod(temp)) || (data.flag / 10 && temp / 10))
			return (0);
		data.flag += temp;
		i++;
	}
	if (mod(data.flag) == 4)
		data.flag -= 4;

	if (arg_uniformisation(&list, argv, argc, i) == 0)
		return (free_all(&stack, &pull, list));

	if (list == NULL)
	{
		printf("Error occured in parsing\n");
		return (0);
	}
	if (!verif_dbl(list))
	{
		printf("Error\n");
		return (0);
	}

	i = 0;
	while (list[i])
	{
		
		stk_tmp = add_back_nod(&stack, new_elem(ft_atoi(list[i])));
		if (stk_tmp == NULL)
			return (free_all(&stack, &pull, list));
		if (data.max < (long)stk_tmp->value)
			data.max = (long)stk_tmp->value;
		else if (data.min > (long)stk_tmp->value)
			data.min = (long)stk_tmp->value;
		i++;
	}
	data.total = i;
	data.currentot = i;
	data.buk_nbr = ((float)ft_sqrt(data.total)); //* (float)0.6);
	if (data.buk_nbr < 1)
		data.buk_nbr = 1;
	disorder = compute_disorder(stack);

//	show_stack(&stack);
//	show_stack(&pull);
	

	if (mod(data.flag) == 1 || (disorder < (float)0.2 && mod(data.flag) == 0)) // Value data.total just to test, we have to do less than 25 op for 5 4 3 2 1
	{
		selection(&data, &stack, &pull);
		bench_mod(data, disorder, 1);
	}
	else if (mod(data.flag) == 2 || (disorder < (float)0.5 && mod(data.flag) == 0))
	{
		buckets(&data, &stack, &pull);
		bench_mod(data, disorder, 2);
	}
	else if (mod(data.flag) == 3 || (disorder >= (float)0.5 && mod(data.flag) == 0))
	{
		if (data.total < 50)
			radix(&data, &stack, &pull, data.total, 10, radix_move_10);
		else
			radix(&data, &stack, &pull, data.total, 2, radix_move);
		bench_mod(data, disorder, 3);
	}

//	printf("\n");
//	show_stack(&stack);
//	show_stack(&pull);

	free_all(&stack, &pull, list);
}
