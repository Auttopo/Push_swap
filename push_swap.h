/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenabde <abenabde@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:36:11 by abenabde          #+#    #+#             */
/*   Updated: 2026/01/11 14:14:55 by jsam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

int	ft_atoi(const char *nptr);
float	compute_disorder(t_stack *s);
void	init_index(t_stack *stack, int size);
void    radix(t_info *info, t_stack **s1, t_stack **s2, int size, int base);

int		add_back_nod(t_stack **stack, t_stack *new);
t_stack	*new_elem(int value);
long	min_select(int total, t_stack *local, int *pos);
void	selection(t_info *d, t_stack **stack, t_stack **pull);


void	buckets(t_info *d, t_stack **stack, t_stack **pull);
void	value_sorter(t_info *d, t_stack **stack, t_stack **pull);
void	efficient_move(t_info *d, t_stack **stack, char *str, int pos);
int		ft_sqrt(int nb);

void	swap(t_info *d, t_stack **s1, char *str);
void	push(t_info *d, t_stack **s1, t_stack **s2, char *str);
void	rotate(t_info *d, t_stack **s, void (*move) (t_stack **), char *str);
void	dblswap(t_info *d, t_stack **s1, t_stack **s2);
void	dblrotate(t_info *d, t_stack **s1, t_stack **s2);
void	dblrrotate(t_info *d, t_stack **s1, t_stack **s2);
void	bubble(t_info *d, t_stack **s1, int size);
void    r_next(t_stack **s);
void    r_prev(t_stack **s);


void	bench_mod(t_info d, float disorder, int strat);


#endif
