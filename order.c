/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:09:31 by gcucino           #+#    #+#             */
/*   Updated: 2022/06/03 16:34:11 by gcucino          ###   ########.fr       */
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

void	make_move(void (*move)(t_stack *), t_stack *s)
{
	move(s);
	if ((*move) == ra)
		write(1, "ra\n", 3);
	else if ((*move) == rb)
		write(1, "rb\n", 3);
	else if ((*move) == pa)
		write(1, "pa\n", 3);
	else if ((*move) == pb)
		write(1, "pb\n", 3);
	else if ((*move) == sa)
		write(1, "sa\n", 3);
	else if ((*move) == sb)
		write(1, "sb\n", 3);
	else if ((*move) == rra)
		write(1, "rra\n", 4);
	else if ((*move) == rrb)
		write(1, "rrb\n", 4);
	else if ((*move) == rr)
		write(1, "rr\n", 3);
	else if ((*move) == rrr)
		write(1, "rrr\n", 4);
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
