/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:44:57 by gcucino           #+#    #+#             */
/*   Updated: 2022/06/03 16:51:30 by gcucino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>

typedef struct s_array
{
	int	*arr;
	int	size;
}				t_array;

typedef struct s_stack
{
	int		size;
	t_array	*a;
	t_array	*b;
	t_array	*lis;
	t_array	*move_a;
	t_array	*move_b;
}				t_stack;
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_buf(int fd);
char	*get_next_line(int fd);
int		ft_strbuf(char **buf, int fd);
int		has_next(char *src);
char	*ft_strndup(char *str, int start, int end);
char	*get_next_token(char **src);
int		ft_strlen_2(char *s);
int		handler_null(char **buf, int fd);
void	fill_tmp(char *dest, char *s1, char *s2);

int		ft_atoi(const char *str, int *ret);
char	**ft_split(char *str, char *charset, int *c);
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
t_stack	*init_stacks(char **input, int size);
void	free_stack(t_stack *s);
void	make_simple_moves(t_stack *s);

//debug
void	print_moves(int moves);
void	print_stack(int *arr, int size);
void	print_stacks(t_stack *s);
void	print_best_move(int move);
void	print_index(int index);
void	print_num(int nbr);

//utils
int		get_max_min(int x, int y, int flag);
int		is_sorted(t_stack *s);
int		*ft_alloc_bzero(int n);
int		ft_abs(int n);
int		ft_sign(int n);

void	move_to_a(t_stack *s, int i);
void	init_move_array(t_stack *s, int size);
void	set_move_b(int *t, int size);
void	rotate_until_0(t_stack *s, int dir[], int i);
void	bin_search_lis(t_array *s, int *p, int *m, int *lenght);
void	order(t_stack *s);
int		is_sorted_not_rotated(t_stack *s);
void	free_array(t_array *a);
int		ft_isin(int n, int *arr, int size);
int		get_best_move(t_stack *s);
int		get_id(int size, int id);
int		get_index_best_move(int *tmp, int size);
#endif
