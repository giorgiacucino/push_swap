/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:53:53 by gcucino           #+#    #+#             */
/*   Updated: 2022/05/25 13:16:37 by gcucino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *s)
{
	int	tmp;

	if (s->a->size < 2)
		return ;
	tmp = s->a->arr[0];
	s->a->arr[0] = s->a->arr[1];
	s->a->arr[1] = tmp;
}

void	sb(t_stack *s)
{
	int	tmp;

	if (s->b->size < 2)
		return ;
	tmp = s->b->arr[0];
	s->b->arr[0] = s->b->arr[1];
	s->b->arr[1] = tmp;
}

void	ss(t_stack *s)
{
	sa(s);
	sb(s);
}

void	pb(t_stack *s)
{
	int	i;
	int	tmp;

	if (s->a->size == 0)
		return ;
	i = 0;
	tmp = s->a->arr[0];
	while (i < s->a->size)
	{
		s->a->arr[i] = s->a->arr[i + 1];
		i++;
	}
	i = s->b->size;
	while (i > 0)
	{
		s->b->arr[i] = s->b->arr[i - 1];
		i--;
	}
	s->b->arr[0] = tmp;
	s->a->size--;
	s->b->size++;
}

void	pa(t_stack *s)
{
	int	i;
	int	tmp;

	if (s->b->size == 0)
		return ;
	i = 0;
	tmp = s->b->arr[0];
	// if (s->size_a == 34 || s->size_a == 35)
	// {
	// 	print_num(tmp);
	// }
	while (i < s->b->size)
	{
		s->b->arr[i] = s->b->arr[i + 1];
		i++;
	}
	i = s->a->size;
	while (i > 0)
	{
		s->a->arr[i] = s->a->arr[i - 1];
		i--;
	}
	s->a->arr[0] = tmp;
	s->b->size--;
	s->a->size++;
}
