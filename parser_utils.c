/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenabde <abenabde@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:05:40 by abenabde          #+#    #+#             */
/*   Updated: 2026/01/13 11:05:40 by abenabde         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
