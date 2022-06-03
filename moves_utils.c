/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:34:57 by gcucino           #+#    #+#             */
/*   Updated: 2022/06/03 16:35:58 by gcucino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_id(int size, int id)
{
	if (size % 2 == 1)
	{
		if (id <= size / 2)
			return (id);
		else
			return (id - size);
	}
	else
	{
		if (id <= size / 2)
			return (id);
		else
			return (id - size);
	}
}

int	get_index_best_move(int *tmp, int size)
{
	int	i;
	int	best;
	int	ret;

	i = 0;
	best = tmp[0];
	ret = 0;
	while (++i < size)
	{
		if (best > tmp[i])
		{
			best = tmp[i];
			ret = i;
		}
	}
	return (ret);
}

int	get_best_move(t_stack *s)
{
	int	i;
	int	*tmp;

	i = -1;
	tmp = ft_alloc_bzero(s->b->size);
	while (++i < s->b->size)
	{
		if (s->move_a->arr[i] >= 0 && s->move_b->arr[i] >= 0)
			tmp[i] = get_max_min(s->move_a->arr[i], s->move_b->arr[i], 1);
		else if (s->move_a->arr[i] < 0 && s->move_b->arr[i] < 0)
			tmp[i] = ft_abs(get_max_min(s->move_a->arr[i],
						s->move_b->arr[i], 0));
		else
			tmp[i] = ft_abs(s->move_a->arr[i]) + ft_abs(s->move_b->arr[i]);
	}
	i = get_index_best_move(tmp, s->b->size);
	free(tmp);
	return (i);
}
