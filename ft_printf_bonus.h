/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenabde <abenabde@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:16:23 by abenabde          #+#    #+#             */
/*   Updated: 2026/01/20 11:16:23 by abenabde         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdarg.h>

typedef struct s_strc
{
	const char	*str;
	size_t		i;
	size_t		count;
}	t_strc;

int		perce_case(t_strc *s, int fd);
int		di_case(t_strc *s, va_list *args, int fd);
int		u_case(t_strc *s, va_list *args, int fd);
int		c_case(t_strc *s, va_list *args, int fd);
int		s_case(t_strc *s, va_list *args, int fd);

void	convert_base(unsigned long long num,
			unsigned long long base, char *tbl, char *dest);
char	*convertor(t_strc *s, unsigned long long n, char indice, int fd);
void	hex_len(unsigned long long n, int *len);
int		p_case(t_strc *s, va_list *args, int fd);
int		x_cases(t_strc *s, va_list *args, char indice, int fd);

int		ft_putstr(char *str, int fd);
int		ft_putnbr(size_t *count, long long n, int fd);
int		no_case(t_strc *s, int fd);
int		parser(t_strc *s, va_list *args, int fd);
int		ft_printf(int fd, const char *intput, ...);

#endif
