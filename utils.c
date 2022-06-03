/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 10:20:00 by gcucino           #+#    #+#             */
/*   Updated: 2022/06/03 17:40:50 by gcucino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sign(int n)
{
	if (n > 0)
		return (1);
	else if (n == 0)
		return (0);
	else
		return (-1);
}

int	ft_abs(int n)
{
	if (n >= 0)
		return (n);
	else
		return (-n);
}

int	*ft_alloc_bzero(int n)
{
	int	i;
	int	*ret;

	ret = (int *) malloc (sizeof(int) * n);
	if (!ret)
		return (NULL);
	i = -1;
	while (++i < n)
		ret[i] = 0;
	return (ret);
}

int	get_max_min(int x, int y, int flag)
{
	int	max;
	int	min;

	if (x > y)
	{
		max = x;
		min = y;
	}
	else
	{
		max = y;
		min = x;
	}
	if (flag == 0)
		return (min);
	else
		return (max);
}
