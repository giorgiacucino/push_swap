/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:14:17 by gcucino           #+#    #+#             */
/*   Updated: 2022/05/17 18:13:55 by gcucino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack *s)
{
	rra(s);
	rrb(s);
}

void	make_move(void (*move)(t_stack *), t_stack *s)
{
	move(s);
	s->moves++;
	// if ((*move) == ra)
	// 	write(1, "ra\n", 3);
	// else if ((*move) == rb)
	// 	write(1, "rb\n", 3);
	// else if ((*move) == pa)
	// 	write(1, "pa\n", 3);
	// else if ((*move) == pb)
	// 	write(1, "pb\n", 3);
	// else if ((*move) == sa)
	// 	write(1, "sa\n", 3);
	// else if ((*move) == sb)
	// 	write(1, "sb\n", 3);
	// else if ((*move) == rra)
	// 	write(1, "rra\n", 4);
	// else if ((*move) == rrb)
	// 	write(1, "rrb\n", 4);
	// else if ((*move) == rr)
	// 	write(1, "rr\n", 3);
	// else if ((*move) == rrr)
	// 	write(1, "rrr\n", 4);
	// write(1, "\n", 1);
	// print_stacks(s);
	// write(1, "\n", 1);
}

void	set_move_b(int *t, int size, int i)
{
	if (i < ((size / 2) + 1))
	{
		t[size - i] = -i;
		t[i] = i;
	}
}

/*
	//write(1, "indice del successore: ", 23);
	//ft_putnbr_fd(succ, 1);
	//write(1, "\n", 1);
*/

void	set_move_a(t_stack *s, int *tmp, int i, int max_a)
{
	int	j;

	j = -1;
	if (s->b[i] > s->a[max_a])
		s->move_a[i] = tmp[(max_a + 1) % s->size_a];
	else
	{
		while (++j < s->size_a - 1)
		{
			if (s->a[j] < s->b[i] && s->a[j + 1] > s->b[i])
			{
				s->move_a[i] = tmp[j + 1];
				break ;
			}
		}
	}
}

void	update_moves(t_stack *s)
{
	int	i;
	int	*tmp;
	int	max_a;

	tmp = ft_alloc_bzero(s->size_a);
	i = -1;
	max_a = 0;
	while (++i < s->size_a)
	{
		set_move_b(tmp, s->size_a, i);
		if (s->a[i] > s->a[max_a])
			max_a = i;
	}
	i = -1;
	while (++i < s->size_b)
	{
		set_move_a(s, tmp, i, max_a);
		set_move_b(s->move_b, s->size_b, i);
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
	tmp = ft_alloc_bzero(s->size_b);
	while (++i < s->size_b)
	{
		if (s->move_a[i] >= 0 && s->move_b[i] >= 0)
			tmp[i] = get_max_min(s->move_a[i], s->move_b[i], 1);
		else if (s->move_a[i] < 0 && s->move_b[i] < 0)
			tmp[i] = ft_abs(get_max_min(s->move_a[i], s->move_b[i], 0));
		else
			tmp[i] = ft_abs(s->move_a[i]) + ft_abs(s->move_b[i]);
	}
	i = get_index_best_move(tmp, s->size_b);
	free(tmp);
	return (i);
}
