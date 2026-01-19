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

#include "get_next_line_bonus.h"


static	ssize_t	endline(char *buf)
{
	ssize_t	i;

	i = 0;
	while (buf[i] != '\n' && buf[i])
		i++;
	return (i);
}

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

static	void	newbuf(char *buf, ssize_t endl, ssize_t readbytes)
{
	ssize_t	i;

	i = 0;
	while (i < readbytes)
	{
		if (endl + 1 + i < readbytes)
			buf[i] = buf[endl + 1 + i];
		else
			buf[i] = '\0';
		i++;
	}
}

static	ssize_t	readline(char *buf, int fd)
{
	ssize_t	readbytes;

	if (buf[0])
		readbytes = ft_strlen(buf);
	else
	{
		readbytes = read(fd, buf, BUFFER_SIZE);
		if (readbytes < 0)
			return (-1);
	}
	return (readbytes);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		readbytes;
	ssize_t		endl;
	int			stop;

	stop = 0;
	if (!veriffd(buf, fd))
		return (NULL);
	line = NULL;
	while (!stop)
	{
		readbytes = readline(buf, fd);
		if (readbytes < 0)
			return (freeline(line));
		endl = endline(buf);
		if (readbytes != endl || readbytes == 0)
			stop = 1;
		line = newline(line, buf, endl, readbytes);
		if (!line)
			return (NULL);
		newbuf(buf, endl, readbytes);
	}
	return (line);
}
/*
#include <stdio.h>
#include <fcntl.h>

int	main()
{
	int i = 0;
	char	buf[1024];
	buf[1024] = 'c';
	printf("%c", buf[1024]);

	return (0);
}*/
