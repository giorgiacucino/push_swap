/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:44:31 by gcucino           #+#    #+#             */
/*   Updated: 2022/05/12 18:15:53 by gcucino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	write(1, "--- stack a ---\n", 16);
	print_stack(s->a, s->size_a);
	write(1, "--- stack b ---\n", 16);
	print_stack(s->b, s->size_b);
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
	ret->a = (int *) malloc (sizeof(int) * i);
	ret->b = (int *) malloc (sizeof(int) * i);
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

	if (argc < 2)
		return (-1);
	if (argc == 2)
		argv = ft_split(argv[1], " ");
	else
		argv++;
	s = init_stacks(argv);
	print_stacks(s);
	if (argc == 2)
		free(argv);
	return (0);
}
