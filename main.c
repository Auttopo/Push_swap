/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenabde <abenabde@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:26:10 by abenabde          #+#    #+#             */
/*   Updated: 2026/01/15 12:20:35 by jsam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

/*
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
	printf("|%d PREV %d IAM %d NEXT|  %d buk\n",
	(*stack)->previous->value,(*stack)->value,
	(*stack)->next->value,(*stack)->bucket);
	while (i < max - 1)
	{
		printf("|%d PREV %d IAM %d NEXT|  %d buk\n",
		temp->previous->value, temp->value, temp->next->value, temp->bucket);
//		printf("|%d|\n", temp->value);
		temp = temp->next;
		i++;
	}
	printf("\n");
}
*/
void	show_stack(t_stack **stack)
{
	t_stack	*temp;

	if (*stack == NULL)
	{
		return ;
	}

	temp = (*stack)->next;
	ft_printf(1, "|%d PREV %d IAM %d NEXT|  %d buk\n",
	(*stack)->previous->value, (*stack)->value,
	(*stack)->next->value, (*stack)->bucket);
	while (temp != *stack)
	{
		ft_printf(1, "|%d PREV %d IAM %d NEXT|  %d buk\n",temp->previous->value, temp->value, temp->next->value, temp->bucket);
		temp = temp->next;
	}
	ft_printf(1, "\n");
}


static int	flag_setup(t_flags f, t_info *data, int argc, char **argv)
{
	int	i;
	int	temp;

	i = 1;
	if (argc < 2)
		return (0);
	while (i < (argc - 1) && (i < 3) && argv[i][1] == '-')
	{
		temp = flag_check(f, argv[i]);
		if ((mod(data->flag) && mod(temp)) || (data->flag / 10 && temp / 10) || temp == 0)
		{
			ft_printf(2, "Error\n");
			return (0);
		}
		data->flag += temp;
		i++;
	}
	if (mod(data->flag) == 4)
		data->flag -= 4;
	return (i);
}

static int	stack_and_data_setup(char **list, t_stack **stack, t_info *data)
{
	int		i;
	t_stack	*stk_tmp;

	i = 0;
	while (list[i])
	{
		stk_tmp = add_back_nod(stack, new_elem(ft_atoi(list[i])));
		if (stk_tmp == NULL)
			return (0);
		if (data->max < (long)stk_tmp->value)
			data->max = (long)stk_tmp->value;
		else if (data->min > (long)stk_tmp->value)
			data->min = (long)stk_tmp->value;
		i++;
	}
	data->total = i;
	data->currentot = i;
	if (data->total > 10)
		data->buk_nbr = ((float)ft_sqrt(data->total) * (float)0.65);
	else
		data->buk_nbr = ((float)ft_sqrt(data->total) * (float)0.8);
	if (data->buk_nbr < 1)
		data->buk_nbr = 1;
	return (1);
}

static void	execution(t_info *data,
		t_stack **stack, t_stack **pull, float disorder)
{
 // Value data.total just to test, we have to do less than 25 op for 5 4 3 2 1   \/
	if (disorder == 0 && mod(data->flag) != 0)
		return (bench_mod(*data, disorder, mod(data->flag)));
	if (mod(data->flag) == 1 || (disorder < (float)0.2 && mod(data->flag) == 0))
	{
		selection(data, stack, pull);
		bench_mod(*data, disorder, 1);
	}
	else if (mod(data->flag) == 2
		|| (disorder < (float)0.5 && mod(data->flag) == 0))
	{
		buckets(data, stack, pull);
		bench_mod(*data, disorder, 2);
	}
	else if (mod(data->flag) == 3
		|| (disorder >= (float)0.5 && mod(data->flag) == 0))
	{
		if (data->total < 50)
			radix(data, stack, pull, 10);
		else
			radix(data, stack, pull, 2);
		bench_mod(*data, disorder, 3);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	float	disorder;
	char	**list;
	t_flags	f;
	t_info	data;

	list = main_init(&data, &f, &data.stack, &data.pull);
	i = flag_setup(f, &data, argc, argv);
	if (!i)
		return (0);
	if (!arg_uniformisation(&list, argv, argc, i))
		return (free_all(&data.stack, &data.pull, list, 0));
	if (list == NULL)
		return (free_all(&data.stack, &data.pull, list, 0));
	if (!verif_dbl(list))
		return (free_all(&data.stack, &data.pull, list, 0));
	if (!stack_and_data_setup(list, &data.stack, &data))
		return (free_all(&data.stack, &data.pull, list, 0));
	disorder = compute_disorder(data.stack);
	execution(&data, &data.stack, &data.pull, disorder);
	show_stack(&data.stack);
	free_all(&data.stack, &data.pull, list, 1);
}
