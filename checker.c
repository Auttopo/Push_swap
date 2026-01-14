/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsam <jsam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 07:45:47 by jsam              #+#    #+#             */
/*   Updated: 2026/01/14 09:40:19 by jsam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdlib.h>

//checker.c checker_utils.c radix_utils.c parser.c utils.c rules1.c rules2.c  display.c ft_printf.c ft_printf_cases.c ft_printf_hex.c parser_utils.c stack.c get_next_line.c get_next_line_utils.c disordermetric.c buckets_utils.c

static int    flag_setup(t_flags f, t_info *data, int argc, char **argv)
{
    int i;
    int temp;

    i = 1;
   	if (argc < 2)
		return (0);
    while (i < (argc - 1) && (i < 3) &&  argv[i][1] == '-')
	{
		temp = flag_check(f, argv[i]);
		if ((mod(data->flag) && mod(temp)) || (data->flag / 10 && temp / 10))
			return (0);
		data->flag += temp;
		i++;
	}
	if (mod(data->flag) == 4)
		data->flag -= 4;
	return (i);
}

static int stack_and_data_setup(char **list, t_stack **stack, t_info *data)
{
    int i;
    t_stack *stk_tmp;

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
	data->buk_nbr = ((float)ft_sqrt(data->total)); 
	if (data->buk_nbr < 1)
		data->buk_nbr = 1;
	return (1);
}

static int list_check(char **list)
{
    if (list == NULL)
    {
        ft_printf("Error occured during parsing\n");
        return (0);
    }
   	if (!verif_dbl(list))
	{
		ft_printf("Error\n");
		return (0);
	}
    return (1);
}



int	main(int argc, char **argv)
{
	int		i;
	float	disorder;
	char	**list;
	char	*line;
	t_flags	f;
	t_info	data;
	t_stack	*stack;
	t_stack	*pull;

	list = main_init(&data, &f, &stack, &pull);
    i = flag_setup(f, &data, argc, argv);
    if (!i)
	return (0);
    if (!arg_uniformisation(&list, argv, argc, i))
		return (free_all(&stack, &pull, list));
	if (!list_check(list))
		return (free_all(&stack, &pull, list));
	if (!stack_and_data_setup(list, &stack, &data))
		return (free_all(&stack, &pull, list));
	readexec_checker(&data, &stack, &pull);
	if (compute_disorder(stack) == 0)
		ft_printf("OK");
	else
		ft_printf("KO");
	free_all(&stack, &pull, list);
}

