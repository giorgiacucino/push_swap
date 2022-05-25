/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 09:34:27 by gcucino           #+#    #+#             */
/*   Updated: 2022/05/25 17:58:59 by gcucino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isin(int n, int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == n)
			return (1);
		i++;
	}
	return (0);
}

/* mio algo, mo provo quello  di mbassett 
void	break_lis(t_stack *s)
{
	int	j;

	j = 0;
	while (s->a->size > s->lis->size)
	{
		if (j < s->lis->size && ft_isin(s->a->arr[0], s->lis->arr, s->lis->size) == 1)
		{
			make_move(ra, s);
			j++;
		}
		else
		{
			make_move(pb, s);
			if (s->b->arr[0] > 0 && s->b->size > 1)
			{
				if (j < s->lis->size && ft_isin(s->a->arr[0], s->lis->arr, s->lis->size) == 1)
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
*/

void	move_to_b(t_stack *s)
{
	int	i;
	int best;
	int	dir[2];
	
	i = -1;
	best = s->size;
	while (++i < s->a->size)
	{
		if (ft_isin(s->a->arr[i], s->lis->arr, s->lis->size) == 0 && (ft_abs(s->move_a->arr[i]) < best || (ft_abs(s->move_a->arr[i]) == best && s->move_a->arr[i] < 0)))
			best = i;
	}
	dir[0] = ft_sign(s->move_a->arr[best]);
	dir[1] = 0;
	rotate_until_0(s, dir, best);
	make_move(pb, s);
}

void	break_lis(t_stack *s)
{
	s->move_a = (t_array *) malloc (sizeof(t_array));
	while (s->a->size > s->lis->size)
	{
		s->move_a->arr = ft_alloc_bzero(s->a->size);
		s->move_a->size = s->a->size;
		set_move_b(s->move_a->arr, s->a->size);
		move_to_b(s);
		free(s->move_a->arr);
	}
	free(s->move_a);
}

void	bin_search_lis(t_array *s, int *p, int *m, int *lenght, int min)
{
	int	lo;
	int	hi;
	int	i;
	int	mid;

	i = 0;
	while (i < s->size)
	{
		lo = 1;
		hi = (*lenght) + 1;
		while (lo < hi)
		{
			mid = lo + ((hi - lo) / 2);
			if (s->arr[m[mid]] < s->arr[i] && s->arr[m[mid]] > min)
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
	t_array	*tmp;
	t_array *tmp2;
	int	lenght;
	int	k;
	int	i;
	int j;

	p = ft_alloc_bzero(s->a->size);
	m = ft_alloc_bzero(s->a->size + 1);
	lenght = 0;
	bin_search_lis(s->a, p, m, &lenght, -2147483647 - 1);
	tmp = (t_array *) malloc (sizeof(t_array));
	tmp->arr = ft_alloc_bzero(lenght);
	tmp->size = lenght;
	k = m[lenght];
	i = lenght - 1;
	while (i > -1)
	{
		tmp->arr[i] = s->a->arr[k];
		k = p[k];
		i--;
	}
	//print_stack(tmp->arr, tmp->size);
	tmp2 = (t_array *) malloc (sizeof(t_array));
	tmp2->arr = ft_alloc_bzero(s->a->size - lenght);
	tmp2->size = 0;
	j = -1;
	while (++j < s->a->size)
	{
		if (s->a->arr[j] != tmp->arr[0])
		{
			tmp2->arr[tmp2->size] = s->a->arr[j];
			tmp2->size++;
		}
		else
			break;
	}
	//print_stack(tmp2->arr, tmp2->size);
	ft_bzero(p, s->a->size);
	ft_bzero(m, s->a->size + 1);
	lenght = 0;
	//print_num(tmp->arr[tmp->size - 1]);
	bin_search_lis(tmp2, p, m, &lenght, tmp->arr[tmp->size - 1]);
	if (tmp2->arr[m[1]] < tmp->arr[tmp->size - 1])
		lenght = 0;
	s->lis = (t_array *) malloc (sizeof(t_array));
	s->lis->arr = ft_alloc_bzero(tmp->size + lenght);
	s->lis->size = tmp->size + lenght;
	k = m[lenght];
	i = tmp->size + lenght - 1;
	while (i > tmp->size - 1)
	{
		s->lis->arr[i] = tmp2->arr[k];
		k = p[k];
		i--;
	}
	i = -1;
	while (++i < tmp->size)
	{
		s->lis->arr[i] = tmp->arr[i];
	}
	//print_stack(s->lis->arr, s->lis->size);
	free(tmp);
	free(tmp2);
	free(p);
	free(m);
}
