/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 10:20:00 by gcucino           #+#    #+#             */
/*   Updated: 2022/05/25 14:48:21 by gcucino          ###   ########.fr       */
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

void	ft_bzero(int* arr, int n)
{
	int	i;
	
	if (!arr)
		return ;
	i = -1;
	while (++i < n)
		arr[i] = 0;
	return ;
}

int	is_sorted(t_stack *s)
{
	int	i;

	if (s->a->size < s->size)
		return (0);
	i = -1;
	while (++i < s->size - 1)
	{
		if (s->a->arr[i] > s->a->arr[i + 1])
			return (0);
	}
	return (1);
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
