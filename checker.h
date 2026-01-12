/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsam <jsam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:11:43 by jsam              #+#    #+#             */
/*   Updated: 2026/01/12 14:05:03 by jsam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
// checker.c checker_utils2.c checker_utils.c disordermetric.c rules1.c rules2.c ft_printf/*.c
typedef struct s_info
{
	int	flag; 
	long max;
	long min;
	int total;
	int	currentot;
	int	buk_nbr;

	int	sa;
	int	sb;
	int ss;
	int pa;
	int pb;
	int ra;
	int rb;
	int rr;
	int rra;
	int	rrb;
	int	rrr;

}	t_info;

typedef struct s_stack
{
	int value;
	int	bucket;
	struct s_stack *next;
	struct s_stack *previous;
	int index;
}	t_stack;

typedef struct s_flags
{
	char	*bench;
	char	*simple;
	char	*medium;
	char	*complex_;
	char	*adaptative;
}	t_flags;


char	**ft_split(char *str, char *charset);
void	rotate(t_info *d, t_stack **s, void (*move)(t_stack **), char *str);
void    r_next(t_stack **s);
void    r_prev(t_stack **s);
t_stack	*add_back_nod(t_stack **stack, t_stack *new);
t_stack	*new_elem(int value);
float	compute_disorder(t_stack *s);
void	swap(t_info *d, t_stack **s1, char *str);
void	push(t_info *d, t_stack **s1, t_stack **s2, char *str);
void	dblrrotate_checker(t_info *d, t_stack **s1, t_stack **s2);
void	dblrotate_checker(t_info *d, t_stack **s1, t_stack **s2);
void	dblswap_checker(t_info *d, t_stack **s1, t_stack **s2);
int     ft_atoi(const char *nptr);
int	ft_sqrt(int nb);
int	ft_printf(const char *input, ...);
#endif
