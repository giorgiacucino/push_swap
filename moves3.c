/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:14:17 by gcucino           #+#    #+#             */
/*   Updated: 2022/06/03 16:40:14 by gcucino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack *s)
{
	rra(s);
	rrb(s);
}

void	set_move_b(int *t, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (i < ((size / 2) + 1))
		{
			if (i != 0)
				t[size - i] = -i;
			t[i] = i;
		}
	}
}

void	set_move_a(t_stack *s, int *min_max)
{
	int	i;
	int	j;

	i = -1;
	while (++i < s->b->size)
	{
		j = -1;
		if (s->b->arr[i] > s->a->arr[min_max[0]])
			s->move_a->arr[i] = get_id(s->a->size, min_max[0] + 1);
		else if (s->b->arr[i] < s->a->arr[min_max[1]])
			s->move_a->arr[i] = get_id(s->a->size, min_max[1]);
		else
		{
			while (++j < s->a->size)
			{
				if (s->a->arr[j] < s->b->arr[i]
					&& s->b->arr[i] < s->a->arr[j + 1])
				{
					s->move_a->arr[i] = get_id(s->a->size, j + 1);
					break ;
				}
			}
		}
	}
}

void	update_moves(t_stack *s)
{
	int	i;
	int	*min_max;

	i = -1;
	min_max = ft_alloc_bzero(2);
	while (++i < s->a->size)
	{
		if (s->a->arr[i] > s->a->arr[min_max[0]])
			min_max[0] = i;
		if (s->a->arr[i] < s->a->arr[min_max[1]])
			min_max[1] = i;
	}
	set_move_a(s, min_max);
	set_move_b(s->move_b->arr, s->b->size);
	free(min_max);
}
