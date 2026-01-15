/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 11:29:41 by jsam              #+#    #+#             */
/*   Updated: 2026/01/15 14:11:22 by jsam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

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

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		i;
	int		j;
	int		start;

	start = 0;
	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	result = malloc(sizeof(char *) * (ft_count_word(str, charset)));
	if (!result)
		return (NULL);
	while (str[i])
	{
		if (ft_is_sep(str[i], charset) == 0)
		{
			start = i;
			result[j] = ft_strdup(str, charset, start);
			while (ft_is_sep(str[i], charset) == 0)
				i++;
			j++;
		}
		i++;
	}
	return (result);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	char *str = argv[1];
	char *charset = argv[2];
	char **test;
	int	i;
	int len;

	i = 0;
	test = ft_split(str, charset);
	while (test[i])
		i++;
	len = i;
	i = 0;
	while(i < len)
	{
		printf("%s\n", test[i]);
		i++;
	}
	return (0);
}*/
