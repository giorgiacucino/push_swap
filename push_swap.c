/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:44:31 by gcucino           #+#    #+#             */
/*   Updated: 2022/05/19 18:35:39 by gcucino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order(t_stack *s)
{
	int	i;

	if (is_sorted(s) == 1)
		return ;
	i = 1;
	while (s->a[i] > s->a[i - 1] && i < s->size_a)
		i++;
	if (i < (s->size_a / 2))
	{
		while (i > 0)
		{
			make_move(ra, s);
			i--;
		}
	}
	else
	{
		while (i < s->size_a)
		{
			make_move(rra, s);
			i++;
		}
	}
}

void	init_move_array(t_stack *s)
{
	s->move_a = ft_alloc_bzero(s->size_b);
	s->move_b = ft_alloc_bzero(s->size_b);
}

t_stack	*init_stacks(char **input)
{
	int		i;
	t_stack	*ret;

	i = 0;
	ret = (t_stack *) malloc (sizeof(t_stack));
	while (input[i] != 0)
		i++;
	ret->size = i;
	ret->moves = 0;
	ret->a = ft_alloc_bzero(i);
	ret->b = ft_alloc_bzero(i);
	ret->size_a = i;
	ret->size_b = 0;
	i = 0;
	while (input[i] != 0)
	{
		ret->a[i] = ft_atoi(input[i]);
		i++;
	}
	return (ret);
}

int	main(int argc, char **argv)
{
	t_stack	*s;
	//int 	i;

	if (argc < 2)
		return (-1);
	if (argc == 2)
		argv = ft_split(argv[1], " ");
	else
		argv++;
	s = init_stacks(argv);
	//print_stacks(s);
	//print_moves(s->moves);
	// print_stacks(s);
	get_lis(s);
	//print_stack(s->lis, s->size_lis);
	break_lis(s);
	//print_stacks(s);
	// write(1, "\n", 1);
	// print_moves(s->moves);
	//i = -1;
	//while (s->size_a < s->size)
	//{
		// print_stacks(s);
	// 	//print_moves(s->moves);
		// write(1, "\n", 1);
		// print_stacks(s);
		//init_move_array(s);
	// 	// if (s->size_a == 88)
	// 	// 	print_stacks(s);
		//update_moves(s);
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
		//move_to_a(s, get_best_move(s));
		// if (s->size_a >= 21 && s->size_a < 25)
		// 	print_stack(s->a, s->size_a);
		//free(s->move_a);
		//free(s->move_b);
	// 	//write(1, "\n", 1);
	//}
	while (s->size_a < s->size)
	{
		init_move_array(s);
		update_moves(s);
		//print_stack(s->move_a, s->size_b);
		//print_stack(s->move_b, s->size_b);
		move_to_a(s, get_best_move(s));
		//print_stacks(s);
		free(s->move_a);
		free(s->move_b);
	}
	// init_move_array(s);
	// update_moves(s);
	//print_moves(s->moves);
	//print_stacks(s);
	order(s);
	//print_stacks(s);
	// print_moves(s->moves);
	free(s->a);
	free(s->b);
	free(s->lis);
	// free(s->move_a);
	// free(s->move_b);
	free(s);
	if (argc == 2)
		free(argv);
	return (0);
}

//array: 1 -4 3 14 15 13 17 -19 7 -2 -17 -18 16 8 -8 -16 -14 19 -13 -11 2 -3 -12 -5 10 6 9 11 5 18 -6 12 -20 -9 -10 -1 0 20 4 -7 -15
