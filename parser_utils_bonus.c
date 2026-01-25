/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenabde <abenabde@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:05:40 by abenabde          #+#    #+#             */
/*   Updated: 2026/01/25 15:00:44 by jsam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
