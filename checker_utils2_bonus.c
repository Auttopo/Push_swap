/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsam <jsam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:44:31 by jsam              #+#    #+#             */
/*   Updated: 2026/01/20 15:22:58 by jsam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	dblswap_checker(t_stack **s1, t_stack **s2)
{
	if (!*s1 && !*s2)
		return ;
	swap_checker(s1);
	swap_checker(s2);
}

int	free_readexec_checker(char *line, char **splitline)
{
	int	i;

	i = 0;
	if (line)
		free(line);
	while (splitline[i])
	{
		free(splitline[i]);
		i++;
	}
	free(splitline);
	return (0);
}

char	*read_line(void)
{
	char	*line;
	char	buffer[42];
	ssize_t	readbytes;
	int		stop;

	stop = 0;
	line = NULL;
	ft_bzero((void *)buffer, 42);
	while (!stop)
	{
		readbytes = read(0, buffer, 41);
		if (!readbytes)
			stop = 1;
		buffer[readbytes] = '\0';
		line = newline(line, buffer, ft_strlen(buffer), ft_strlen(buffer));
		if (line == NULL)
			return (NULL);
		if (!verif_cmd(buffer))
		{
			free(line);
			return (NULL);
		}
	}
	return (line);
}

int	verif_cmd(char *buffer)
{
	int	result;
	int	i;

	i = 0;
	result = 0;
	result += str_comp(buffer, "sa\n");
	result += str_comp(buffer, "sb\n");
	result += str_comp(buffer, "ss\n");
	result += str_comp(buffer, "pa\n");
	result += str_comp(buffer, "pb\n");
	result += str_comp(buffer, "ra\n");
	result += str_comp(buffer, "rb\n");
	result += str_comp(buffer, "rr\n");
	result += str_comp(buffer, "rra\n");
	result += str_comp(buffer, "rrb\n");
	result += str_comp(buffer, "rrr\n");
	result += str_comp(buffer, "");
	if (!result)
		return (0);
	return (1);
}
