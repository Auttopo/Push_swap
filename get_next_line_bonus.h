/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsam <jsam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:35:52 by jsam              #+#    #+#             */
/*   Updated: 2026/01/18 18:50:03 by jsam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

ssize_t	ft_strlen(char *str);
void	ft_strlcat(char *dst, char *src, int endl);
char	*freeline(char *line);
int		veriffd(char *buf, int fd);
char	*get_next_line(int fd);
char	*newline(char *line, char *buf, ssize_t endl, ssize_t readbytes);

#endif
