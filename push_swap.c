/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:44:31 by gcucino           #+#    #+#             */
/*   Updated: 2022/05/26 18:57:26 by gcucino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_simple_moves(t_stack *s)
{
	int	best;

	if (is_sorted_not_rotated(s) == 1)
		return ;
	get_lis(s);
	//print_stack(s->lis->arr, s->lis->size);
	best = s->lis->size;
	sa(s);
	free_array(s->lis);
	get_lis(s);
	if (s->lis->size > best || is_sorted_not_rotated(s) == 1)
		make_move(sa, s);
	free_array(s->lis);
	sa(s);
}

void	free_array(t_array *a)
{
	free(a->arr);
	free(a);
}

void	free_stack(t_stack *s)
{
	if (s->a != NULL)
		free(s->a);
	if (s->b != NULL)
		free(s->b);
	if (s->lis != NULL)
		free(s->lis);
	if (s != NULL)
		free(s);
}

void	order(t_stack *s)
{
	int	i;

	if (is_sorted(s) == 1)
		return ;
	i = 1;
	while (s->a->arr[i] > s->a->arr[i - 1] && i < s->a->size)
		i++;
	if ((i < (s->a->size / 2) && s->a->size % 2 == 0) || (i <= (s->a->size / 2) && s->a->size % 2 == 1))
	{
		while (i > 0)
		{
			make_move(ra, s);
			i--;
		}
	}
	else
	{
		while (i < s->a->size)
		{
			make_move(rra, s);
			i++;
		}
	}
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

t_stack	*init_stacks(char **input, int size)
{
	int		i;
	t_stack	*ret;

	ret = (t_stack *) malloc (sizeof(t_stack));
	ret->size = size;
	ret->a = (t_array *) malloc (sizeof(t_array));
	ret->a->arr = ft_alloc_bzero(size);
	ret->a->size = size;
	ret->b = (t_array *) malloc (sizeof(t_array));
	ret->b->arr = ft_alloc_bzero(size);
	ret->b->size = 0;
	ret->lis = NULL;
	i = 0;
	while (input[i] != 0)
	{
		if (ft_atoi(input[i], &ret->a->arr[i]) == 0 || ft_isin(ret->a->arr[i], ret->a->arr, i) == 1)
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
//&& ft_isin(ret->a->arr[i], ret->a->arr, i + 1) == 0

int	main(int argc, char **argv)
{
	t_stack	*s;
	int 	i;

	if (argc < 2)
		return (-1);
	if (argc == 2)
		argv = ft_split(argv[1], " ", &i);
	else
	{
		argv++;
		i = argc - 1;
	}
	s = init_stacks(argv, i);
	if (s == NULL)
		return (-1);
	make_simple_moves(s);
	if (is_sorted_not_rotated(s) == 0)
	{
		get_lis(s);
		//print_stack(s->lis->arr, s->lis->size);
		break_lis(s);
		while (s->a->size < s->size)
		{
			init_move_array(s, s->b->size);
			update_moves(s);
			move_to_a(s, get_best_move(s));
			free_array(s->move_a);
			free_array(s->move_b);
		}
		free_array(s->lis);
	}
	order(s);
	//print_stack(s->a->arr, s->a->size);
	free_array(s->a);
	free_array(s->b);
	free(s);
	if (argc == 2)
		free(argv);
	return (0);
}
