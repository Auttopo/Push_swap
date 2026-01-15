/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsam <jsam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 08:09:16 by jsam              #+#    #+#             */
/*   Updated: 2026/01/15 15:10:02 by jsam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	readexec_checker(t_info *d, t_stack **stack, t_stack **pull)
{
	char	buffer[10];
	char	*line;
	int		stop;
	char	**splitline;
	int		i;

	i = 0;
	stop = 0;
	line = NULL;
	ft_bzero((void *)buffer, 10);
	while (!stop)
	{
		if (read(0, buffer, 9) == 0)
			stop = 1;
		else
			line = newline(line, buffer, ft_strlen(buffer), ft_strlen(buffer));
	}
	splitline = ft_split(line, "\n");
	if (!splitline)
		return ;
	while (splitline[i])
	{
		exec_checker(splitline[i], d, stack, pull);
		i++;
	}
}

void	exec_checker(char *line, t_info *d, t_stack **stack, t_stack **pull)
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
}
