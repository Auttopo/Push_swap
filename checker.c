/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsam <jsam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:08:45 by jsam              #+#    #+#             */
/*   Updated: 2026/01/12 17:46:56 by jsam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdlib.h>
#include <stdio.h> // TODO delete before push
#include <unistd.h>

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

void	opexec(char *op, t_stack **stack, t_stack **pull, t_info *data)		
{
	if (str_comp(op, "ra"))
		rotate(data, stack, r_next, "ra");
	else if (str_comp(op, "rb"))
		rotate(data, pull, r_next, "rb");
	else if (str_comp(op, "rra"))
		rotate(data, stack, r_prev, "rra");
	else if (str_comp(op, "rrb"))
		rotate(data, pull, r_prev, "rrb");
	else if (str_comp(op, "sa"))
		swap(data, stack, "sa");
	else if (str_comp(op, "sb"))
		swap(data, pull, "sb");
	else if (str_comp(op, "ss"))
		dblswap_checker(data, stack, pull);
	else if (str_comp(op, "pa"))
		push(data, stack, pull, "pa");
	else if (str_comp(op, "pb"))
		push(data, pull, stack, "pb");
	else if (str_comp(op, "rrr"))
		dblrrotate_checker(data, stack, pull);
	else if (str_comp(op, "rr"))
		dblrotate_checker(data, stack, pull);
}

void	ft_bzero(char *s, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		s[i] = 0;
		i++;
	}
}


int	main(int argc, char **argv)
{
	int		i;
	int		temp;
	int		flg;
	int		opstrsize;
	int		opstrcount;
	int		stop;
	int		sizetmp;
	float	disorder;
	char	**list;
	char	**optab;
	char	*opstr;
	char	buffer[1024];
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
	stack = NULL;
	ft_bzero(buffer, 1024);

//	__builtin_printf("%s\n OUT\n", argv[4]);

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
	opstrsize = 0;
	stop = 0;
//	while (!stop)
//	{
		sizetmp = read(0, buffer, 1024);
		opstrsize += sizetmp;
		if (sizetmp == 0)
			stop = 1;
//	}
//	opstr = malloc(sizeof(char) * opstrsize + 1);
//	if (!opstr)
//		return (0);
	optab = ft_split(buffer, "\n");
	if (!optab)
		return (0);
	i = 0;
	while (optab[i])
	{
		opexec(optab[i], &stack, &pull, &data);
		i++;
	}
	if (compute_disorder(stack) == (float)0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
//	printf("%d", STDIN_FILENO);

	freeall(optab, i);
	free(optab);
//	free(opstr);
	return (0);
}
