/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 09:34:27 by gcucino           #+#    #+#             */
/*   Updated: 2022/06/04 12:45:19 by gcucino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	better_breaker(t_stack *s, int *j)
{
	if (s->b->arr[0] > 0 && s->b->size > 2)
	{
		if ((*j) < s->lis->size
			&& ft_isin(s->a->arr[0], s->lis->arr, s->lis->size) == 1)
		{
			make_move(rr, s);
			(*j)++;
		}
		else
			make_move(rb, s);
	}
}

void	break_lis(t_stack *s)
{
	int	j;

	j = 0;
	while (s->a->size > s->lis->size)
	{
		if (j < s->lis->size
			&& ft_isin(s->a->arr[0], s->lis->arr, s->lis->size) == 1)
		{
			make_move(ra, s);
			j++;
		}
		else
		{
			make_move(pb, s);
			better_breaker(s, &j);
		}
	}
}

t_array	*get_lis_from_arr(int *p, int *m, t_array *a)
{
	t_array	*tmp;
	int		lenght;
	int		k;
	int		i;

	lenght = 0;
	bin_search_lis(a, p, m, &lenght);
	tmp = (t_array *) malloc (sizeof(t_array));
	tmp->arr = ft_alloc_bzero(lenght);
	tmp->size = lenght;
	k = m[lenght];
	i = lenght - 1;
	while (i > -1)
	{
		tmp->arr[i] = a->arr[k];
		k = p[k];
		i--;
	}
	return (tmp);
}

t_array	*copy_arr_circ(t_array *src, t_array *src2, int max)
{
	t_array	*tmp;
	int		i;

	tmp = (t_array *) malloc (sizeof(t_array));
	tmp->arr = ft_alloc_bzero(src2->size);
	tmp->size = -1;
	while (++tmp->size < src->size)
		tmp->arr[tmp->size] = src->arr[tmp->size];
	while (++max < src2->size)
	{
		tmp->arr[tmp->size] = src2->arr[max];
		tmp->size++;
	}
	i = 0;
	while (src2->arr[i] != src->arr[0])
	{
		tmp->arr[tmp->size] = src2->arr[i];
		i++;
		tmp->size++;
	}
	return (tmp);
}

void	get_lis(t_stack *s)
{
	int		*p;
	int		*m;
	t_array	*first;
	t_array	*second;

	p = ft_alloc_bzero(s->a->size);
	m = ft_alloc_bzero(s->a->size + 1);
	first = get_lis_from_arr(p, m, s->a);
	second = copy_arr_circ(first, s->a, m[first->size]);
	s->lis = get_lis_from_arr(p, m, second);
	free_array(first);
	free_array(second);
	free(p);
	free(m);
}
