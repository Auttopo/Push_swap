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

static	int	args_verif(int argc)
{
	if (argc < 2)
		return (0);
	return (1);
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
	return (1);
}

static	int	list_check(char **list)
{
	if (!list)
	{
		ft_printf(2, "Error\n");
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
	char	**list;
	t_flags	f;
	t_info	data;

	list = main_init(&data, &f, &data.stack, &data.pull);
	if (!args_verif(argc))
		return (list_check(NULL));
	if (!arg_uniformisation(&list, argv, argc, 1))
		return (free_all(&data.stack, &data.pull, list, 0));
	if (!list_check(list))
		return (free_all(&data.stack, &data.pull, list, 0));
	if (!stack_and_data_setup(list, &data.stack, &data))
		return (free_all(&data.stack, &data.pull, list, 0));
	if (0 >= readexec_checker(&data.stack, &data.pull))
		return (free_all(&data.stack, &data.pull, list, 0));
	if (compute_disorder(data.stack) == 0 && !data.pull)
		ft_printf(1, "OK\n");
	else
		ft_printf(1, "KO\n");
	free_all(&data.stack, &data.pull, list, 1);
	return (0);
}
