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
#include "get_next_line_bonus.h"

void	dblswap_checker(t_info *d, t_stack **s1, t_stack **s2)
{
	if (!*s1 || !*s2)
		return ;
	swap(d, s1, "");
	swap(d, s2, "");
}

void	dblrotate_checker(t_info *d, t_stack **s1, t_stack **s2)
{
	if (!*s1 || !*s2)
		return ;
	rotate(d, s1, r_next, "");
	rotate(d, s2, r_next, "");
}

void	dblrrotate_checker(t_info *d, t_stack **s1, t_stack **s2)
{
	if (!*s1 || !*s2)
		return ;
	rotate(d, s1, r_prev, "");
	rotate(d, s2, r_prev, "");
}

int	readexec_checker(t_info *d, t_stack **stack, t_stack **pull)
{
	char	*line;
	char	**splitline;
	int		i;

	i = 0;
	line = NULL;
	line = read_line();
	if (!line)
		return (1);
/*	else if (line[0]=='\n')
		return (0);*/
	splitline = ft_split(line, "\n");
	if (!splitline || !(*splitline))
		return (0);
	while (splitline[i])
	{
		if (!exec_checker(splitline[i], d, stack, pull))
			return (free_readexec_checker(line, splitline));
		i++;
	}
	free_readexec_checker(line, splitline);
	return (1);
}

int	exec_checker(char *line, t_info *d, t_stack **stack, t_stack **pull)
{
	if (str_comp(line, "sa"))
		swap_checker(d, stack);
	else if (str_comp(line, "sb"))
		swap_checker(d, pull);
	else if (str_comp(line, "ss"))
		dblswap_checker(d, stack, pull);
	else if (str_comp(line, "pa"))
		push_checker(d, stack, pull);
	else if (str_comp(line, "pb"))
		push_checker(d, pull, stack);
	else if (str_comp(line, "ra"))
		rotate_checker(d, stack, r_next);
	else if (str_comp(line, "rb"))
		rotate_checker(d, pull, r_next);
	else if (str_comp(line, "rr"))
		dblrotate_checker(d, stack, pull);
	else if (str_comp(line, "rra"))
		rotate_checker(d, stack, r_prev);
	else if (str_comp(line, "rrb"))
		rotate_checker(d, pull, r_prev);
	else if (str_comp(line, "rrr"))
		dblrrotate_checker(d, stack, pull);
	else
		return (0);
	return (1);
}
