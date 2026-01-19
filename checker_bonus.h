/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsam <jsam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 07:56:12 by jsam              #+#    #+#             */
/*   Updated: 2026/01/18 18:09:31 by jsam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
/*
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
*/
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

	void	*pradix;

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

// BUCKETS UTILS . C
int		ft_sqrt(int nb);
void	efficient_move(t_info *d, t_stack **stack, char *str, int pos);
int		first_select(t_info d, t_stack *local, long *comp, int buck);
int		max_in_bucket(t_stack *local, int buck);

// UTILS . C
long	ft_atoi(const char *nptr);
void	clear_stack(t_stack **stack);
int		free_all(t_stack **s, t_stack **p, char **list, int flag);
char	**main_init(t_info *d, t_flags *f, t_stack **s, t_stack **p);

// STACK . C
void	init_list(t_stack **stack, t_stack *new);
t_stack	*add_back_nod(t_stack **stack, t_stack *new);
t_stack	*new_elem(int value);

// RULES1 . C
void	push(t_info *d, t_stack **dest, t_stack **src, char *str);
void	r_next(t_stack **s);
void	r_prev(t_stack **s);
void	rotate(t_info *d, t_stack **s, void (*move)(t_stack **), char *str);
void	swap(t_info *d, t_stack **s, char *str);

//RULES2 . C
void	dblswap_checker(t_info *d, t_stack **s1, t_stack **s2);
void	dblrotate_checker(t_info *d, t_stack **s1, t_stack **s2);
void	dblrrotate_checker(t_info *d, t_stack **s1, t_stack **s2);

// DISORDERMETRIC . C
float	compute_disorder(t_stack *s);

// get_next_line
/*ssize_t	ft_strlen(char *str);
void	ft_strlcat(char *dst, char *src, int endl);
char	*freeline(char *line);
int		veriffd(char *buf, int fd);
char	*get_next_line(int fd);
char	*newline(char *line, char *buf, ssize_t endl, ssize_t readbytes);
*/

// PARSER . C
int		arg_checker(char *src);
char	*extract_str(char *str, int *i);
int		arg_parser(char *src, char **list, int *e);
int		arg_uniformisation(char ***list, char **str, int max, int i);

// PARSER_UTILS . C
int		verif_dbl(char **list);
int		mod(int flag);
int		str_comp(char *str, char *str2);
int		flag_check(t_flags f, char *str);

// checker_utils.c
int		readexec_checker(t_info *d, t_stack **stack, t_stack **pull);
int		exec_checker(char *line, t_info *d, t_stack **stack, t_stack **pull);

// checker_utils2.c
int		arg_checker_checker(int argc, char **argv);
int		verif_cmd(char *buffer);
int		free_readexec_checker(char *line, char **splitline);
char	*read_line(void);

// DISPLAY . C
void	putstr_log(t_info *d, char *s);
void	bench_mod(t_info d, float disorder, int strat);

// FT_PRINTF
int		ft_printf(int fd, const char *intput, ...);

// ft_split
char	**ft_split(char *str, char *charset);
char	**freesplit(char **result);
// ft_bzero.c
void	ft_bzero(void *s, size_t n);

// checker_rules1.c
void	push_checker(t_info *d, t_stack **dest, t_stack **src);
void	rotate_checker(t_info *d, t_stack **s, void (*move)(t_stack **));
void	swap_checker(t_info *d, t_stack **s);
#endif
