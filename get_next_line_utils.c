/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 08:38:06 by gcucino           #+#    #+#             */
/*   Updated: 2022/06/03 12:44:15 by gcucino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen_2(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

int	handler_null(char **buf, int fd)
{
	buf[fd] = get_buf(fd);
	if (buf[fd] == NULL)
		return (-1);
	return (1);
}

int	has_next(char *src)
{
	int	i;

	i = 0;
	if (src == NULL)
		return (0);
	while (src[i] != '\0' && src[i] != '\n')
		i++;
	if (src[i] == '\0')
		return (0);
	return (1);
}

void	fill_tmp(char *dest, char *s1, char *s2)
{
	int	i;
	int	j;

	i = -1;
	while (s1[++i] != 0)
		dest[i] = s1[i];
	j = -1;
	while (s2[++j] != 0)
		dest[i + j] = s2[j];
	dest[i + j] = '\0';
}
