/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenabde <abenabde@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:31:22 by abenabde          #+#    #+#             */
/*   Updated: 2026/01/18 16:22:58 by jsam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int				value;
	int				bucket;
	struct s_stack	*next;
	struct s_stack	*previous;
	int				index;
}	t_stack;

typedef struct s_info
{
	t_stack	*stack;
	t_stack	*pull;

	int		flag;
	long	max;
	long	min;
	int		total;
	int		currentot;
	int		buk_nbr;

	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;

}	t_info;

typedef struct s_flags
{
	char	*bench;
	char	*simple;
	char	*medium;
	char	*complex_;
	char	*adaptative;
}	t_flags;

void	init_index(t_stack *stack, int size);
void	radix(t_info *info, t_stack **stack, t_stack **pull, int base);
void	radix_move(t_info *info, t_stack **s1, t_stack **s2, int min_max);
void	radix_move_10(t_info *info, t_stack **s1, t_stack **s2, int min_max);
char	*definestr_rotate(int min_max, int i, int base);
t_stack	*find_minmax(t_stack *pstack, int min_max);
int		find_max(int size, int base);

// FT_PRINTF
int		ft_printf(int fd, const char *intput, ...);

// DISORDERMETRIC . C
float	compute_disorder(t_stack *s);

// UTILS . C
long	ft_atoi(const char *nptr);
void	clear_stack(t_stack **stack);
int		free_all(t_stack **s, t_stack **p, char **list, int flag);
char	**main_init(t_info *d, t_flags *f, t_stack **s, t_stack **p);

// MAERGE . C
void	merge_short(t_info *d, t_stack **stack, t_stack **pull);

// SELECTION . C
long	min_select(int total, t_stack *local, int *pos);
void	selection(t_info *d, t_stack **stack, t_stack **pull);

// STACK . C
void	init_list(t_stack **stack, t_stack *new);
t_stack	*add_back_nod(t_stack **stack, t_stack *new);
t_stack	*new_elem(long value);
//int	add_front_nod(t_stack **stack, t_stack *new);

// BUCKETS . C
void	buckets(t_info *d, t_stack **stack, t_stack **pull);
void	buk_setup(t_info d, t_stack *local, t_stack *(*select)(int, t_stack*));

// BUCKETS UTILS . C
int		ft_sqrt(int nb);
void	efficient_move(t_info *d, t_stack **stack, char *str, int pos);
int		first_select(int total, t_stack *local, int buck);
int		max_in_bucket(t_stack *local, int buck);

// RULES1 . C
void	push(t_info *d, t_stack **dest, t_stack **src, char *str);
void	r_next(t_stack **s);
void	r_prev(t_stack **s);
void	rotate(t_info *d, t_stack **s, void (*move)(t_stack **), char *str);
void	swap(t_info *d, t_stack **s, char *str);

//RULES2 . C
//void	dblswap(t_info *d, t_stack **s1, t_stack **s2);
//void	dblrotate(t_info *d, t_stack **s1, t_stack **s2);
//void	dblrrotate(t_info *d, t_stack **s1, t_stack **s2);

// STACK . C
void	init_list(t_stack **stack, t_stack *new);
t_stack	*add_back_nod(t_stack **stack, t_stack *new);
int		add_front_nod(t_stack **stack, t_stack *new);
t_stack	*new_elem(long value);

// PARSER . C
int		arg_checker(char *src);
char	*extract_str(char *str, int *i);
int		arg_parser(char *src, char **list, int *e);
int		arg_uniformisation(char ***list, char **str, int max, int i);

// PARSER . C
int		verif_dbl(char **list);
int		mod(int flag);
int		str_comp(char *str, char *str2);
int		flag_check(t_flags f, char *str);

// DISPLAY . C
void	putstr_log(t_info *d, char *s);
void	bench_mod(t_info d, float disorder, int strat);

#endif
