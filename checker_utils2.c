/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsam <jsam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:44:31 by jsam              #+#    #+#             */
/*   Updated: 2026/01/15 14:25:56 by jsam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	arg_checker_checker(int argc, char **argv)
{
	int	i;
	int	j;
	int	mincheck;

	mincheck = 0;
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if(argv[i][j] == '-' && mincheck == 0)
			{
				j++;
				mincheck = 1;
			}
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (0);
			j++;
		}
		mincheck = 0;
		i++;
	}
	return (1);
}
