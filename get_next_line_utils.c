/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsam <jsam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:34:11 by jsam              #+#    #+#             */
/*   Updated: 2026/01/15 15:34:57 by jsam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

ssize_t	ft_strlen(char *str)
{
	ssize_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_strlcat(char *dst, char *src, int endl)
{
	int	i;
	int	ldst;

	i = 0;
	ldst = ft_strlen(dst);
	while (src[i] && i < endl)
	{
		dst[ldst + i] = src[i];
		i++;
	}
	dst[ldst + i] = '\0';
}

int	veriffd(char *buf, int fd)
{
	int	i;

	i = 0;
	if (BUFFER_SIZE <= 0)
		return (0);
	if (fd < 0)
	{
		while (i < BUFFER_SIZE)
		{
			buf[i] = '\0';
			i++;
		}
		return (0);
	}
	return (1);
}

char	*freeline(char *line)
{
	if (line)
		free(line);
	return (NULL);
}
