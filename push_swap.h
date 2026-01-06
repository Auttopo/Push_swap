/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenabde <abenabde@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:36:11 by abenabde          #+#    #+#             */
/*   Updated: 2025/12/29 17:11:11 by jsam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_info
{
	long max;
	long min;
	int total;
	int	currentot;
	int	buk_nbr;

}	t_info;

typedef struct s_stack
{
	int value;
	int	bucket;
	struct s_stack *next;
	struct s_stack *previous;

}	t_stack;
//utils.c
int	ft_atoi(const char *nptr);
float compute_disorder(t_stack *s, int size);

int		add_back_nod(t_stack **stack, t_stack *new);
t_stack	*new_elem(int value);
long	min_select(int total, t_stack *local, int *pos);
void	selection(int total, t_stack **stack, t_stack **pull);


void	buckets(t_info *d, t_stack **stack, t_stack **pull);
void	value_sorter(t_info d, t_stack **stack, t_stack **pull);

void	swap(t_stack **s1, char *str);
void	push(t_stack **s1, t_stack **s2, char *str);
void	rotate(t_stack **s, void (*move) (t_stack **), char *str);
void	dblswap(t_stack **s1, t_stack **s2);
void	dblrotate(t_stack **s1, t_stack **s2);
void	dblrrotate(t_stack **s1, t_stack **s2);
void	bubble(t_stack **s1, int size);
void    r_next(t_stack **s);
void    r_prev(t_stack **s);
#endif
