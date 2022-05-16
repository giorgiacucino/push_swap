/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:44:57 by gcucino           #+#    #+#             */
/*   Updated: 2022/05/13 14:21:46 by gcucino          ###   ########.fr       */
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

#endif
