/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsam <jsam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:33:43 by jsam              #+#    #+#             */
/*   Updated: 2026/01/19 14:24:47 by jsam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

char	*newline(char *line, char *buf, ssize_t	endl, ssize_t readbytes)
{
	char	*newline;
	int		lnewline;
	ssize_t	size;

	size = endl;
	lnewline = ft_strlen(line);
	if (endl != readbytes)
		size++;
	lnewline += size;
	newline = malloc(sizeof(char) * (lnewline + 1));
	if (!newline)
	{
		free(line);
		return (NULL);
	}
	newline[0] = '\0';
	if (line)
		ft_strlcat(newline, line, ft_strlen(line));
	ft_strlcat(newline, buf, size);
	if (line)
		free(line);
	return (newline);
}
