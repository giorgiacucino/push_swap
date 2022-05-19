/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:37:00 by gcucino           #+#    #+#             */
/*   Updated: 2022/05/19 12:27:42 by gcucino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_dir(t_stack *s, int arr, int dir)
{
	if (arr == 0)
	{
		if (dir == 1)
			make_move(ra, s);
		if (dir == -1)
			make_move(rra, s);
	}
	else
	{
		if (dir == 1)
			make_move(rb, s);
		if (dir == -1)
			make_move(rrb, s);
	}
}

void	rotate_together(t_stack *s, int dir)
{
	if (dir == 1)
		make_move(rr, s);
	if (dir == -1)
		make_move(rrr, s);
}

void	rotate_until_0(t_stack *s, int dir[], int i)
{
	while (dir[0] != 0)
	{
		rotate_dir(s, 0, dir[0]);
		s->move_a[i] -= dir[0];
		dir[0] = ft_sign(s->move_a[i]);
	}
	while (dir[1] != 0)
	{
		rotate_dir(s, 1, dir[1]);
		s->move_b[i] -= dir[1];
		dir[1] = ft_sign(s->move_b[i]);
	}
}

void	move_to_a(t_stack *s, int i)
{
	int	dir[2];

	dir[0] = ft_sign(s->move_a[i]);
	dir[1] = ft_sign(s->move_b[i]);
	while (dir[0] == dir[1] && dir[0] != 0 && dir[1] != 0)
	{
		rotate_together(s, dir[0]);
		s->move_a[i] -= dir[0];
		s->move_b[i] -= dir[1];
		dir[0] = ft_sign(s->move_a[i]);
		dir[1] = ft_sign(s->move_b[i]);
	}
	rotate_until_0(s, dir, i);
	// if (s->size_a == 87)
	// 	print_stacks(s);
	if (dir[0] == 0 && dir[1] == 0)
	{
		make_move(pa, s);
		// if (s->size_a == 87)
		// 	print_stacks(s);
	}
}
