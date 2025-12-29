/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsam <jsam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 19:42:40 by jsam              #+#    #+#             */
/*   Updated: 2025/12/29 17:27:50 by jsam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	min;
	int	result;

	min = 1;
	result = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			min = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result *= 10;
		result += *nptr - 48;
		nptr++;
	}
	return (result * min);
}

float compute_disorder(t_stack *s, int size)
{
	int	mistakes;
	int	total;
	int	i;
	int	tmp;
	int	j;
	int	k;
	float	metric;
	int	n;

	n = size;

	mistakes = 0;
	total = 0;
	i = 0;
	while (i < size)
	{
		tmp = s->value;
		j = 0;
		while (j < n)
		{
			if (s->next->value < tmp)
				mistakes++;
			s = s->next;
			total++;
			j++;
		}
		n--;
		i++;
		k = 0;
		while (k < i)
		{
			s = s->next;
			k++;
		}
	}
	metric =(float)mistakes / (float)total;
	return (metric);
}


