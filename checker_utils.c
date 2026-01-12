/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsam <jsam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:22:32 by jsam              #+#    #+#             */
/*   Updated: 2026/01/12 13:57:01 by jsam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

char	*freeall(char **tab, int j)
{

	int	i;

	if (!tab)
		return NULL;
	i = 0;
	while (i < j)
	{
		free(tab[i]);
		i++;
	}
	return NULL;
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		i;
	int		j;
	int		start;

	start = 0;
	i = 0;
	j = 0;
	result = malloc(sizeof(char *) * (ft_count_word(str, charset) + 1));
	if (!result)
		return NULL;
	while (str[i])
	{
		if (ft_is_sep(str[i], charset) == 0)
		{
			start = i;
			result[j] = ft_strdup(str, charset, start);
			if (!result[j])
			{
				freeall(result, j);
				return NULL;
			}
			while (ft_is_sep(str[i], charset) == 0)
				i++;
			j++;
		}
		i++;
	}
	result[j] = NULL;
	return (result);
}
