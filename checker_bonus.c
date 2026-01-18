/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsam <jsam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 07:45:47 by jsam              #+#    #+#             */
/*   Updated: 2026/01/18 17:20:44 by jsam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include <stdlib.h>

static	int	flag_setup(t_flags f, t_info *data, int argc, char **argv)
{
	int	i;
	int	temp;

	i = 1;
	if (argc < 2)
		return (0);
	while (i < (argc - 1) && (i < 3) && argv[i][1] == '-')
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

static	int	stack_and_data_setup(char **list, t_stack **stack, t_info *data)
{
	int		i;
	t_stack	*stk_tmp;

	i = 0;
	while (list[i])
	{
		stk_tmp = add_back_nod(stack, new_elem(ft_atoi(list[i])));
		if (stk_tmp == NULL)
		{
			ft_printf(2, "Error\n");
			return (0);
		}
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

static	int	list_check(char **list)
{
	if (!list)
	{
		ft_printf(2, "Error occured during parsing\n");
		return (0);
	}
	if (!verif_dbl(list))
	{
		ft_printf(2, "Error\n");
		return (0);
	}
	return (1);
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
		return (free_all(&data.stack, &data.pull, list));
	if (!list_check(list))
		return (free_all(&data.stack, &data.pull, list));
	if (!stack_and_data_setup(list, &data.stack, &data))
		return (free_all(&data.stack, &data.pull, list));
	if (!readexec_checker(&data, &data.stack, &data.pull))
		return (free_all(&data.stack, &data.pull, list));
	if (compute_disorder(data.stack) == 0 && !data.pull)
		ft_printf(1, "OK\n");
	else
		ft_printf(1, "KO\n");
	free_all(&data.stack, &data.pull, list);
	return (0);
}
