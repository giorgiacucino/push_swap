/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:57:08 by gcucino           #+#    #+#             */
/*   Updated: 2022/05/25 13:10:24 by gcucino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *s)
{
	int	tmp;
	int	i;

	if (s->a->size < 2)
		return ;
	tmp = s->a->arr[0];
	i = 0;
	while (i < s->a->size)
	{
		s->a->arr[i] = s->a->arr[i + 1];
		i++;
	}
	s->a->arr[i - 1] = tmp;
}

void	rb(t_stack *s)
{
	int	tmp;
	int	i;

	if (s->b->size < 2)
		return ;
	tmp = s->b->arr[0];
	i = 0;
	while (i < s->b->size)
	{
		s->b->arr[i] = s->b->arr[i + 1];
		i++;
	}
	s->b->arr[i - 1] = tmp;
}

void	rr(t_stack *s)
{
	ra(s);
	rb(s);
}

void	rra(t_stack *s)
{
	int	tmp;
	int	i;

	if (s->a->size < 2)
		return ;
	tmp = s->a->arr[s->a->size - 1];
	i = s->a->size;
	while (i > 0)
	{
		s->a->arr[i] = s->a->arr[i - 1];
		i--;
	}
	s->a->arr[0] = tmp;
}

void	rrb(t_stack *s)
{
	int	tmp;
	int	i;

	if (s->b->size < 2)
		return ;
	tmp = s->b->arr[s->b->size - 1];
	i = s->b->size;
	while (i > 0)
	{
		s->b->arr[i] = s->b->arr[i - 1];
		i--;
	}
	s->b->arr[0] = tmp;
}
