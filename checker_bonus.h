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

}	t_info;

// BUCKETS UTILS . C
int		ft_sqrt(int nb);

// UTILS . C
long	ft_atoi(const char *nptr);
void	clear_stack(t_stack **stack);
int		free_all(t_stack **s, t_stack **p, char **list, int flag);
char	**main_init(t_info *d, t_stack **s, t_stack **p);

// STACK . C
void	init_list(t_stack **stack, t_stack *new);
t_stack	*add_back_nod(t_stack **stack, t_stack *new);
t_stack	*new_elem(long value);

// DISORDERMETRIC . C
float	compute_disorder(t_stack *s);

// get_next_line
ssize_t	ft_strlen(char *str);
void	ft_strlcat(char *dst, char *src, int endl);
char	*newline(char *line, char *buf, ssize_t endl, ssize_t readbytes);

// PARSER . C
int		arg_checker(char *src);
char	*extract_str(char *str, int *i);
int		arg_parser(char *src, char **list, int *e);
int		arg_uniformisation(char ***list, char **str, int max, int i);

// PARSER_UTILS . C
int		verif_dbl(char **list);
int		str_comp(char *str, char *str2);

// checker_utils.c
int		readexec_checker(t_stack **stack, t_stack **pull);
int		exec_checker(char *line, t_stack **stack, t_stack **pull);

// checker_utils2.c
void	dblswap_checker(t_stack **s1, t_stack **s2);
int		free_readexec_checker(char *line, char **splitline);
char	*read_line(void);
int		verif_cmd(char *buffer);

// FT_PRINTF
int		ft_printf(int fd, const char *intput, ...);

// ft_split
char	**ft_split(char *str, char *charset);
char	**freesplit(char **result);

// ft_bzero.c
void	ft_bzero(void *s, size_t n);

// checker_rules1.c
void	push_checker(t_stack **dest, t_stack **src);
void	rotate_checker(t_stack **s, void (*move)(t_stack **));
void	swap_checker(t_stack **s);
void	r_next(t_stack **s);
void	r_prev(t_stack **s);

#endif
