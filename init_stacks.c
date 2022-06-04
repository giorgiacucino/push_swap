/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:04:22 by gcucino           #+#    #+#             */
/*   Updated: 2022/06/04 11:20:03 by gcucino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_array(t_array *a)
{
	free(a->arr);
	free(a);
}

void	free_stack(t_stack *s)
{
	if (s->a != NULL)
		free_array(s->a);
	if (s->b != NULL)
		free_array(s->b);
	if (s->lis != NULL)
		free_array(s->lis);
	if (s != NULL)
		free(s);
}

void	init_move_array(t_stack *s, int size)
{
	s->move_a = (t_array *) malloc (sizeof(t_array));
	s->move_a->arr = ft_alloc_bzero(size);
	s->move_a->size = size;
	s->move_b = (t_array *) malloc (sizeof(t_array));
	s->move_b->arr = ft_alloc_bzero(size);
	s->move_b->size = size;
}

void	alloc_stacks(t_stack *ret, int size)
{	
	ret->size = size;
	ret->a = (t_array *) malloc (sizeof(t_array));
	ret->a->arr = ft_alloc_bzero(size);
	ret->a->size = size;
	ret->b = (t_array *) malloc (sizeof(t_array));
	ret->b->arr = ft_alloc_bzero(size);
	ret->b->size = 0;
	ret->lis = NULL;
}

t_stack	*init_stacks(char **input, int size)
{
	int		i;
	t_stack	*ret;

	ret = (t_stack *) malloc (sizeof(t_stack));
	alloc_stacks(ret, size);
	i = 0;
	while (input[i] != 0)
	{
		if (ft_atoi(input[i], &ret->a->arr[i]) == 0
			|| ft_isin(ret->a->arr[i], ret->a->arr, i) == 1)
			break ;
		i++;
	}
	if (i < size)
	{
		free_stack(ret);
		write(2, "Error\n", 6);
		return (NULL);
	}
	return (ret);
}
