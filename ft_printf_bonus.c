/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenabde <abenabde@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:32:44 by abenabde          #+#    #+#             */
/*   Updated: 2026/01/20 14:58:15 by jsam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putstr(char *str, int fd)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (write(fd, &str[i], 1) < 1)
			return (0);
		i++;
	}
	return (1);
}

int	ft_putnbr(size_t *count, long long n, int fd)
{
	char	c;

	if (n < 0)
	{
		if (write(fd, "-", 1) < 1)
			return (0);
		*count += 1;
		n = n * -1;
	}
	c = (n % 10 + '0');
	if (n > 9)
		ft_putnbr(count, (n / 10), fd);
	if (write(fd, &c, 1) < 1)
		return (0);
	*count += 1;
	return (1);
}

int	no_case(t_strc *s, int fd)
{
	if (s->str[s->i] == '\0')
		return (0);
	if (perce_case(s, fd) == 0)
		return (0);
	if (write(fd, &s->str[s->i], 1) < 1)
		return (0);
	s->count += 1;
	return (1);
}

int	parser(t_strc *s, va_list *args, int fd)
{
	int	check;

	s->i += 1;
	check = 1;
	if (s->str[s->i] == 'c')
		check = c_case(s, args, fd);
	else if (s->str[s->i] == 's')
		check = s_case(s, args, fd);
	else if (s->str[s->i] == 'p')
		check = p_case(s, args, fd);
	else if (s->str[s->i] == 'd' || s->str[s->i] == 'i')
		check = di_case(s, args, fd);
	else if (s->str[s->i] == 'x')
		check = x_cases(s, args, 'x', fd);
	else if (s->str[s->i] == 'X')
		check = x_cases(s, args, 'X', fd);
	else if (s->str[s->i] == 'u')
		check = u_case(s, args, fd);
	else if (s->str[s->i] == '%')
		check = perce_case(s, fd);
	else
		check = no_case(s, fd);
	s->i += 1;
	return (check);
}

int	ft_printf(int fd, const char *input, ...)
{
	va_list	args;
	t_strc	s;

	va_start(args, input);
	s.i = 0;
	s.str = input;
	s.count = 0;
	while (s.str[s.i])
	{
		if (s.str[s.i] == '%')
		{
			if (parser(&s, &args, fd) == 0)
				return (-1);
		}
		else
		{
			if (write(fd, &s.str[s.i], 1) < 1)
				return (-1);
			s.count += 1;
			s.i++;
		}
	}
	va_end(args);
	return (s.count);
}
