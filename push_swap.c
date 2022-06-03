/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:44:31 by gcucino           #+#    #+#             */
/*   Updated: 2022/06/03 16:23:35 by gcucino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	moves(t_stack *s)
{
	init_move_array(s, s->b->size);
	update_moves(s);
	move_to_a(s, get_best_move(s));
	free_array(s->move_a);
	free_array(s->move_b);
}

void	make_magic(t_stack *s)
{
	get_lis(s);
	break_lis(s);
	while (s->a->size < s->size)
		moves(s);
	free_array(s->lis);
}

int	main(int argc, char **argv)
{
	t_stack	*s;
	int		i;

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
		make_magic(s);
	order(s);
	free_array(s->a);
	free_array(s->b);
	free(s);
	if (argc == 2)
		free(argv);
	return (0);
}
