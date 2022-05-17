/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:57:08 by gcucino           #+#    #+#             */
/*   Updated: 2022/05/17 14:51:53 by gcucino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *s)
{
	int	tmp;
	int	i;

	if (s->size_a < 2)
		return ;
	tmp = s->a[0];
	i = 0;
	while (i < s->size_a)
	{
		s->a[i] = s->a[i + 1];
		i++;
	}
	s->a[i - 1] = tmp;
}

void	rb(t_stack *s)
{
	int	tmp;
	int	i;

	if (s->size_b < 2)
		return ;
	tmp = s->b[0];
	i = 0;
	while (i < s->size_b)
	{
		s->b[i] = s->b[i + 1];
		i++;
	}
	s->b[i - 1] = tmp;
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

	if (s->size_a < 2)
		return ;
	tmp = s->a[s->size_a - 1];
	i = s->size_a;
	while (i > 0)
	{
		s->a[i] = s->a[i - 1];
		i--;
	}
	s->a[0] = tmp;
}

void	rrb(t_stack *s)
{
	int	tmp;
	int	i;

	if (s->size_b < 2)
		return ;
	tmp = s->b[s->size_b - 1];
	i = s->size_b;
	while (i > 0)
	{
		s->b[i] = s->b[i - 1];
		i--;
	}
	s->b[0] = tmp;
}
