/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenabde <abenabde@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:01:29 by abenabde          #+#    #+#             */
/*   Updated: 2026/01/25 15:00:29 by jsam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "checker_bonus.h"

int	arg_checker(char *src)
{
	int	i;
	int	e;
	int	temp;

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
		if (src[i - 1] == '-' || src[i] == '-')
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
	while (((str[*i] >= '0') && (str[*i] <= '9')) || (str[*i] == '-'))
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
	list[*e] = NULL;
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
