/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:09:31 by gcucino           #+#    #+#             */
/*   Updated: 2022/06/03 13:10:41 by gcucino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order(t_stack *s)
{
	int	i;

	if (is_sorted(s) == 1)
		return ;
	i = 1;
	while (s->a->arr[i] > s->a->arr[i - 1] && i < s->a->size)
		i++;
	if ((i < (s->a->size / 2) && s->a->size % 2 == 0)
		|| (i <= (s->a->size / 2) && s->a->size % 2 == 1))
	{
		while (i > 0)
		{
			make_move(ra, s);
			i--;
		}
	}
	else
	{
		while (i < s->a->size)
		{
			make_move(rra, s);
			i++;
		}
	}
}

void	make_simple_moves(t_stack *s)
{
	int	best;

	if (is_sorted_not_rotated(s) == 1)
		return ;
	get_lis(s);
	best = s->lis->size;
	sa(s);
	free_array(s->lis);
	get_lis(s);
	if (s->lis->size > best || is_sorted_not_rotated(s) == 1)
		make_move(sa, s);
	free_array(s->lis);
	sa(s);
}
