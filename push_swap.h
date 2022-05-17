/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:44:57 by gcucino           #+#    #+#             */
/*   Updated: 2022/05/17 12:09:21 by gcucino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>

typedef struct s_stack
{
	int		size;
	int		*a;
	int		*b;
	int		size_a;
	int		size_b;
	int		*lis;
	int		size_lis;
	int		moves;
	int		*move_a;
	int		*move_b;
	int		is_sorted;
}				t_stack;

int		ft_atoi(const char *str);
char	**ft_split(char *str, char *charset);
void	ft_putnbr_fd(int n, int fd);
void	sa(t_stack *s);
void	sb(t_stack *s);
void	pb(t_stack *s);
void	pa(t_stack *s);
void	ra(t_stack *s);
void	rb(t_stack *s);
void	rr(t_stack *s);
void	rra(t_stack *s);
void	rrb(t_stack *s);
void	rrr(t_stack *s);
void	break_lis(t_stack *s);
void	get_lis(t_stack *s);
void	make_move(void (*move)(t_stack *), t_stack *s);
void	update_moves(t_stack *s);
int		get_best_move(t_stack *s);

//debug
void	print_moves(int moves);
void	print_stack(int *arr, int size);
void	print_stacks(t_stack *s);
void	print_best_move(int move);

//utils
int		get_max_min(int x, int y, int flag);
int		is_sorted(t_stack *s);
int		*ft_alloc_bzero(int n);
int		ft_abs(int n);
int		ft_sign(int n);

void	move_to_a(t_stack *s, int i);

#endif
