/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:53:53 by gcucino           #+#    #+#             */
/*   Updated: 2022/05/20 10:35:02 by gcucino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *s)
{
	int	tmp;

	if (s->size_a < 2)
		return ;
	tmp = s->a[0];
	s->a[0] = s->a[1];
	s->a[1] = tmp;
}

void	sb(t_stack *s)
{
	int	tmp;

	if (s->size_b < 2)
		return ;
	tmp = s->b[0];
	s->b[0] = s->b[1];
	s->b[1] = tmp;
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

	if (s->size_a == 0)
		return ;
	i = 0;
	tmp = s->a[0];
	while (i < s->size_a)
	{
		s->a[i] = s->a[i + 1];
		i++;
	}
	i = s->size_b;
	while (i > 0)
	{
		s->b[i] = s->b[i - 1];
		i--;
	}
	s->b[0] = tmp;
	s->size_a--;
	s->size_b++;
}

void	pa(t_stack *s)
{
	int	i;
	int	tmp;

	if (s->size_b == 0)
		return ;
	i = 0;
	tmp = s->b[0];
	// if (s->size_a == 34 || s->size_a == 35)
	// {
	// 	print_num(tmp);
	// }
	while (i < s->size_b)
	{
		s->b[i] = s->b[i + 1];
		i++;
	}
	i = s->size_a;
	while (i > 0)
	{
		s->a[i] = s->a[i - 1];
		i--;
	}
	s->a[0] = tmp;
	s->size_b--;
	s->size_a++;
}
