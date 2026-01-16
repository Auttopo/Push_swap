/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsam <jsam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:44:31 by jsam              #+#    #+#             */
/*   Updated: 2026/01/16 17:23:41 by jsam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	free_readexec_checker(char *line, char **splitline)
{
	int	i;

	i = 0;
	free(line);
	while (splitline[i])
	{
		free(splitline[i]);
		i++;
	}
	free(splitline);
	return (0);
}

int	verif_cmd(char **splitline)
{
	int	result;
	int	i;

	i = 0;
	result = 1;
	while (splitline[i])
	{
		result = 0;
		result += str_comp(splitline[i], "sa");
		result += str_comp(splitline[i], "sb");
		result += str_comp(splitline[i], "ss");
		result += str_comp(splitline[i], "pa");
		result += str_comp(splitline[i], "pb");
		result += str_comp(splitline[i], "ra");
		result += str_comp(splitline[i], "rb");
		result += str_comp(splitline[i], "rr");
		result += str_comp(splitline[i], "rra");
		result += str_comp(splitline[i], "rrb");
		result += str_comp(splitline[i], "rrr");
		if (!result)
		{
			free(splitline);
			return (0);
		}
		i++;
	}
	return (1);
}

