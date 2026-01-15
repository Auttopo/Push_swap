/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cases.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenabde <abenabde@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:34:38 by abenabde          #+#    #+#             */
/*   Updated: 2025/12/08 14:34:38 by abenabde         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	perce_case(t_strc *s, int fd)
{
	if (write(fd, "%", 1) < 1)
		return (0);
	s->count += 1;
	return (1);
}

int	di_case(t_strc *s, va_list *args, int fd)
{
	int	temp;

	temp = va_arg(*args, int);
	if (ft_putnbr(&s->count, temp, fd) < 1)
		return (0);
	return (1);
}

int	u_case(t_strc *s, va_list *args, int fd)
{
	unsigned int	temp;

	temp = va_arg(*args, unsigned int);
	if (ft_putnbr(&s->count, temp, fd) < 1)
		return (0);
	return (1);
}

int	c_case(t_strc *s, va_list *args, int fd)
{
	char	temp;

	temp = va_arg(*args, int);
	if (write(fd, &temp, 1) < 1)
		return (0);
	s->count += 1;
	return (1);
}

int	s_case(t_strc *s, va_list *args, int fd)
{
	char	*temp;
	size_t	len;

	len = 0;
	temp = va_arg(*args, char *);
	if (temp == NULL)
	{
		if (write(fd, "(null)", 6) < 1)
			return (0);
		s->count += 6;
		return (1);
	}
	if (ft_putstr(temp, fd) < 1)
		return (0);
	while (temp[len])
		len++;
	s->count += len;
	return (1);
}
