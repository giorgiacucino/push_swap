/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:44:31 by gcucino           #+#    #+#             */
/*   Updated: 2022/05/25 19:01:14 by gcucino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_simple_moves(t_stack *s)
{
	int	best;
	best = num_lis(s->a->arr, s->a->size);
	sa(s);
	if (num_lis(s->a->arr, s->a->size) > best)
	{
		make_move(sa, s);
		best = num_lis(s->a->arr, s->a->size);
	}
	sa(s);
	ra(s);
	if (num_lis(s->a->arr, s->a->size) > best)
	{
		make_move(ra, s);
		best = num_lis(s->a->arr, s->a->size);
	}
	ra(s);
	rra(s);
	if (num_lis(s->a->arr, s->a->size) > best)
	{
		make_move(rra, s);
		best = num_lis(s->a->arr, s->a->size);
	}
	rra(s);
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
		if (ft_atoi(input[i], &ret->a->arr[i]) == 0)
			break ;
		i++;
	}
	if (i < size)
	{
		free_stack(ret);
		return (NULL);
	}
	return (ret);
}

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
	//print_stacks(s);
	//print_moves(s->moves);
	make_simple_moves(s);
	//print_stacks(s);
	// if (is_sorted(s) == 1)
	// 	return (0);
	get_lis(s);
	//print_stack(s->lis->arr, s->lis->size);
	break_lis(s);
	//print_stacks(s);
	// write(1, "\n", 1);
	// print_moves(s->moves);
	//i = -1;
	while (s->a->size < s->size)
	{
		// print_stacks(s);
	// 	//print_moves(s->moves);
		// write(1, "\n", 1);
		// print_stacks(s);
		init_move_array(s, s->b->size);
	// 	// if (s->size_a == 88)
	// 	// 	print_stacks(s);
		update_moves(s);
	// 	if (s->size_a >= 25 && s->size_a < 30)
	// // 	// 	print_stacks(s);
	// 	{
	// 		write(1, "\n", 1);
	// 		print_stack(s->move_a, s->size_b);
	// 		print_stack(s->move_b, s->size_b);
	// 		write(1, "\n", 1);
	// 	}
	// 	// if (s->size_a == 88)
	// 	// {
	// 	// 	write(1, "\n", 1);
	// 	// 	print_stacks(s);
	// 		// print_stack(s->move_a, s->size_b);
	// 		// print_stack(s->move_b, s->size_b);
	// 	// 	print_best_move(get_best_move(s));
	// 	// 	write(1, "\n", 1);
	// 	// }
		move_to_a(s, get_best_move(s));
		// if (s->size_a >= 21 && s->size_a < 25)
		// 	print_stack(s->a, s->size_a);
		free_array(s->move_a);
		free_array(s->move_b);
	// 	//write(1, "\n", 1);
	}
	//while (s->size_a < s->size)
	//{
	//	init_move_array(s);
	//	update_moves(s);
		//print_stack(s->move_a, s->size_b);
		//print_stack(s->move_b, s->size_b);
		// if (s->size_a == 33 || s->size_a == 34)
		// {
		// 	write(1, "\nculo1", 6);
		// 	print_stacks(s);
		// 	fflush(stdout);
		// }
		//move_to_a(s, get_best_move(s));
		// if (s->size_a == 34)
		// {
		// 	write(1, "\nculo2", 6);
		// 	print_stacks(s);
		// 	fflush(stdout);
		// }
		//free(s->move_a);
		//free(s->move_b);
	//}
	// init_move_array(s);
	// update_moves(s);
	//print_moves(s->moves);
	//print_stacks(s);
	order(s);
	//print_stacks(s);
	// print_moves(s->moves);
	free_array(s->a);
	free_array(s->b);
	free_array(s->lis);
	// free(s->move_a);
	// free(s->move_b);
	free(s);
	if (argc == 2)
		free(argv);
	return (0);
}
