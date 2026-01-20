/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsam <jsam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 08:09:16 by jsam              #+#    #+#             */
/*   Updated: 2026/01/19 16:32:43 by jsam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	dblrotate_checker(t_stack **s1, t_stack **s2)
{
	if (!*s1 || !*s2)
		return ;
	rotate_checker(s1, r_next);
	rotate_checker(s2, r_next);
}

static void	dblrrotate_checker(t_stack **s1, t_stack **s2)
{
	if (!*s1 || !*s2)
		return ;
	rotate_checker(s1, r_prev);
	rotate_checker(s2, r_prev);
}

static int	readexec_return(char *line)
{
	if (!line)
		return (-1);
	if (line[0] == '\0')
		return (1);
	return (0);
}

int	readexec_checker(t_stack **stack, t_stack **pull)
{
	char	*line;
	char	**splitline;
	int		i;

	i = 0;
	line = NULL;
	line = read_line();
	if (readexec_return(line) != 0)
		return (readexec_return(line));
	splitline = ft_split(line, "\n");
	if (!splitline)
	{
		free(line);
		return (0);
	}
	if (!(*splitline))
		return (free_readexec_checker(line, splitline));
	while (splitline[i])
	{
		if (!exec_checker(splitline[i], stack, pull))
			return (free_readexec_checker(line, splitline));
		i++;
	}
	free_readexec_checker(line, splitline);
	return (1);
}

int	exec_checker(char *line, t_stack **stack, t_stack **pull)
{
	if (str_comp(line, "sa"))
		swap_checker(stack);
	else if (str_comp(line, "sb"))
		swap_checker(pull);
	else if (str_comp(line, "ss"))
		dblswap_checker(stack, pull);
	else if (str_comp(line, "pa"))
		push_checker(stack, pull);
	else if (str_comp(line, "pb"))
		push_checker(pull, stack);
	else if (str_comp(line, "ra"))
		rotate_checker(stack, r_next);
	else if (str_comp(line, "rb"))
		rotate_checker(pull, r_next);
	else if (str_comp(line, "rr"))
		dblrotate_checker(stack, pull);
	else if (str_comp(line, "rra"))
		rotate_checker(stack, r_prev);
	else if (str_comp(line, "rrb"))
		rotate_checker(pull, r_prev);
	else if (str_comp(line, "rrr"))
		dblrrotate_checker(stack, pull);
	else
		return (0);
	return (1);
}
