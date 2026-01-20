/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 11:29:41 by jsam              #+#    #+#             */
/*   Updated: 2026/01/18 18:49:20 by jsam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "checker_bonus.h"

int	ft_is_sep(char a, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] && a != charset[i])
		i++;
	if (charset[i] == '\0')
		return (0);
	return (1);
}

int	ft_count_word(char *str, char *charset)
{
	int	result;
	int	i;
	int	lf;

	i = 0;
	lf = 0;
	result = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (ft_is_sep(str[i], charset) == 0 && lf == 0)
		{
			lf = 1;
			result++;
		}
		else if (ft_is_sep(str[i], charset) == 1 && lf == 1)
			lf = 0;
		i++;
	}
	return (result);
}

char	*ft_strdup(char *src, char *charset, int start)
{
	char	*srccpy;
	int		i;

	i = 0;
	while (src[start + i] && ft_is_sep(src[start + i], charset) == 0)
		i++;
	srccpy = malloc(i * sizeof(char) + 1);
	if (!srccpy)
		return (NULL);
	i = 0;
	while (src[start + i] && ft_is_sep(src[start + i], charset) == 0)
	{
		srccpy[i] = src[start + i];
		i++;
	}
	srccpy[i] = '\0';
	return (srccpy);
}

char	**freesplit(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str || !charset)
		return (NULL);
	result = malloc(sizeof(char *) * (1 + (ft_count_word(str, charset))));
	if (!result)
		return (NULL);
	while (str[i])
	{
		if (ft_is_sep(str[i], charset) == 0)
		{
			result[j] = ft_strdup(str, charset, i);
			if (!result[j])
				return (freesplit(result));
			i += (int)ft_strlen(result[j]);
			j++;
		}
		i++;
	}
	result[j] = NULL;
	return (result);
}
