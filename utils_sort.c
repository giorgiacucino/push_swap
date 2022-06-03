/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:40:15 by gcucino           #+#    #+#             */
/*   Updated: 2022/06/03 17:40:37 by gcucino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted_interval(t_array *a, int start, int end)
{
	int	i;

	i = start - 1;
	while (++i < end - 1)
	{
		if (a->arr[i] > a->arr[i + 1])
			return (0);
	}
	return (1);
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

int	is_sorted_not_rotated(t_stack *s)
{
	int	i;
	int	min;

	if (s->a->size < s->size)
		return (0);
	if (is_sorted(s) == 1)
		return (1);
	i = 0;
	min = 0;
	while (++i < s->size)
	{
		if (s->a->arr[i] < s->a->arr[min])
			min = i;
	}
	if (is_sorted_interval(s->a, min, s->size) == 0)
		return (0);
	if (s->a->arr[s->size - 1] > s->a->arr[0])
		return (0);
	if (is_sorted_interval(s->a, 0, min) == 0)
		return (0);
	return (1);
}
