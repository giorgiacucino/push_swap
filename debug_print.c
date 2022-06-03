/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 09:55:09 by gcucino           #+#    #+#             */
/*   Updated: 2022/06/03 16:41:09 by gcucino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_num(int nbr)
{
	write(1, "--- numero ---\n", 16);
	ft_putnbr_fd(nbr, 1);
	write(1, "\n", 1);
}

void	print_moves(int moves)
{
	write(1, "--- mosse fatte ---\n", 21);
	ft_putnbr_fd(moves, 1);
	write(1, "\n", 1);
	write(1, "\n", 1);
}

void	print_stack(int *arr, int size)
{
	int	i;

	i = 0;
	write(1, "array: ", 7);
	while (i < size)
	{
		ft_putnbr_fd(arr[i], 1);
		if (i != size - 1)
			write(1, " ", 1);
		i++;
	}
	write(1, "\nsize: ", 7);
	ft_putnbr_fd(size, 1);
	write(1, "\n", 1);
}

void	print_stacks(t_stack *s)
{
	write(1, "\n", 1);
	write(1, "--- stack a ---\n", 16);
	print_stack(s->a->arr, s->a->size);
	write(1, "--- stack b ---\n", 16);
	print_stack(s->b->arr, s->b->size);
}
