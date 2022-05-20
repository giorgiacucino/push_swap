/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 09:34:27 by gcucino           #+#    #+#             */
/*   Updated: 2022/05/20 11:53:47 by gcucino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* mio algo, mo provo quello  di mbassett */
void	break_lis(t_stack *s)
{
	int	j;

	j = 0;
	while (s->size_a > s->size_lis)
	{
		if (j < s->size_lis && s->a[0] == s->lis[j])
		{
			make_move(ra, s);
			j++;
		}
		else
		{
			make_move(pb, s);
			if (s->b[0] > (s->mid / s->size) && s->size_b > 1)
			{
				if (j < s->size_lis && s->a[0] == s->lis[j])
				{
					make_move(rr, s);
					j++;
				}
				else
					make_move(rb, s);
			}
		}
	}
}

// void	break_lis(t_stack *s)
// {
// 	int	j;
// 	int i;

// 	j = 0;
// 	i = 0;
// 	while (s->size_a > s->size_lis)
// 	{
// 		if (j < s->size_lis && (s->a[0] == s->lis[j] || (i == 0 && s->a[0] < )))
// 		{
// 			make_move(ra, s);
// 			if (j < s->size_lis && s->a[0] == s->lis[j])
// 				j++;
// 		}
// 		else if (j == s->size_lis)
// 		{
// 			i = 1;
// 			j = 0;
// 		}
// 		else
// 		{
// 			make_move(pb, s);
// 			if (s->b[0] >  && s->size_b > 1)
// 			{
// 				if (j < s->size_lis && s->a[0] == s->lis[j])
// 				{
// 					make_move(rr, s);
// 					j++;
// 				}
// 				else
// 					make_move(rb, s);
// 			}
// 		}
// 	}
// }

void	bin_search_lis(t_stack *s, int *p, int *m, int *lenght)
{
	int	lo;
	int	hi;
	int	i;
	int	mid;

	i = 0;
	while (i < s->size_a)
	{
		lo = 1;
		hi = (*lenght) + 1;
		while (lo < hi)
		{
			mid = lo + ((hi - lo) / 2);
			if (s->a[m[mid]] < s->a[i])
				lo = mid + 1;
			else
				hi = mid;
		}
		p[i] = m[lo - 1];
		m[lo] = i;
		if (lo > (*lenght))
			(*lenght) = lo;
		i++;
	}
}

void	get_lis(t_stack *s)
{
	int	*p;
	int	*m;
	int	lenght;
	int	k;
	int	i;

	p = ft_alloc_bzero(s->size_a);
	m = ft_alloc_bzero(s->size_a + 1);
	lenght = 0;
	bin_search_lis(s, p, m, &lenght);
	s->lis = ft_alloc_bzero(lenght);
	s->size_lis = lenght;
	k = m[lenght];
	i = lenght - 1;
	while (i > -1)
	{
		s->lis[i] = s->a[k];
		k = p[k];
		i--;
	}
	free(p);
	free(m);
}
