/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:44:31 by gcucino           #+#    #+#             */
/*   Updated: 2022/05/13 17:11:32 by gcucino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	write(1, "--- stack a ---\n", 16);
	print_stack(s->a, s->size_a);
	write(1, "--- stack b ---\n", 16);
	print_stack(s->b, s->size_b);
}

int	*ft_alloc_bzero(int n)
{
    int	i;
	int	*ret;

	ret = (int *) malloc (sizeof(int) * n);
	if (!ret)
		return (NULL);
    i = -1;
    while (++i < n)
		ret[i] = 0;
	return (ret);
}

void	make_move(void (*move)(t_stack *), t_stack *s)  
{  
	move(s);
	//print_stacks(s);
	s->moves++;
	//print_moves(s->moves);
}

void	init_move_array(t_stack *s)
{
	int	i;
	
	i = 0;
	s->move_a = ft_alloc_bzero(s->size_b);
	s->move_b = ft_alloc_bzero(s->size_b);
	while (++i < ((s->size_b / 2) + 1))
	{
		s->move_b[s->size_b - i] = -i;
		s->move_b[i] = i;
	}
}

void	break_lis(t_stack *s)
{
	int	j;

	j = 0;
	while (j < s->size_lis)
	{
		if (s->a[0] == s->lis[j])
		{
			make_move(ra, s);
			j++;
		}
		else
		{
			make_move(pb, s);
			/*7 da modificare in seguito*/
			if (s->b[0] > 7 && s->size_b > 1)
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

void	get_lis(t_stack *s)
{
	int	*p;
	int	*m;
	int	lenght;
	int	lo;
	int	hi;
  
	p = ft_alloc_bzero(s->size_a);
	m = ft_alloc_bzero(s->size_a + 1);
	lenght = 0;
	int i = 0;
	while (i < s->size_a)
	{
		lo = 1;
		hi = lenght + 1;
    	while (lo < hi)
		{
			int mid = lo + ((hi-lo)/2);
      		if (s->a[m[mid]] < s->a[i])
				lo = mid + 1;
			else
				hi = mid;
    	}
		int newL = lo;
    	p[i] = m[newL - 1];
		m[newL] = i;
    	
		if (newL > lenght)
			lenght = newL;
		i++;
	}
	s->lis = ft_alloc_bzero(lenght);
	s->size_lis = lenght;
	int k = m[lenght];
	i = lenght - 1;
	while (i > -1)
	{
		s->lis[i] = s->a[k];
		k = p[k];
		i--;
	}
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

	if (argc < 2)
		return (-1);
	if (argc == 2)
		argv = ft_split(argv[1], " ");
	else
		argv++;
	s = init_stacks(argv);
	get_lis(s);
	break_lis(s);
	print_stacks(s);
	init_move_array(s);
	print_stack(s->move_b, s->size_b);
	if (argc == 2)
		free(argv);
	return (0);
}
