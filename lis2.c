/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:38:30 by gcucino           #+#    #+#             */
/*   Updated: 2022/06/03 16:25:51 by gcucino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isin(int n, int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == n)
			return (1);
		i++;
	}
	return (0);
}

void	bin_search_lis(t_array *s, int *p, int *m, int *lenght)
{
	int	lo;
	int	hi;
	int	i;
	int	mid;

	i = 0;
	while (i < s->size)
	{
		lo = 1;
		hi = (*lenght) + 1;
		while (lo < hi)
		{
			mid = lo + ((hi - lo) / 2);
			if (s->arr[m[mid]] < s->arr[i])
				lo = mid + 1;
			else
				hi = mid;
		}
		p[i] = m[lo - 1];
		m[lo] = i;
		if (lo > (*lenght))
			(*lenght) = lo;
		i++;
	}
}
