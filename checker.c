/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:49:14 by gcucino           #+#    #+#             */
/*   Updated: 2022/06/04 12:32:43 by gcucino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*elaborate_input(int argc, char **argv, int *i)
{
	t_stack	*s;

	if (argc == 2)
		argv = ft_split(argv[1], " ", i);
	else
	{
		argv++;
		(*i) = argc - 1;
	}
	s = init_stacks(argv, *i);
	if (argc == 2)
		free_matrix(argv, *i);
	return (s);
}

void	write_result_and_free(t_stack *s)
{
	if (is_sorted(s) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(s);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		c;

	i = 0;
	c = 0;
	while (s1[i] != 0 && s2[i] != 0 && s1[i] == s2[i] && i < n)
		i++;
	if (i < n)
		c = (unsigned char) s1[i] - (unsigned char) s2[i];
	return (c);
}

int	elaborate_instruction(t_stack *s, char *instr)
{
	if (ft_strncmp(instr, "sa", 2) == 0)
		sa(s);
	else if (ft_strncmp(instr, "sb", 2) == 0)
		sb(s);
	else if (ft_strncmp(instr, "rrb", 3) == 0)
		rrb(s);
	else if (ft_strncmp(instr, "rra", 3) == 0)
		rra(s);
	else if (ft_strncmp(instr, "rrr", 3) == 0)
		rrr(s);
	else if (ft_strncmp(instr, "ra", 2) == 0)
		ra(s);
	else if (ft_strncmp(instr, "rb", 2) == 0)
		rb(s);
	else if (ft_strncmp(instr, "rr", 2) == 0)
		rr(s);
	else if (ft_strncmp(instr, "pa", 2) == 0)
		pa(s);
	else if (ft_strncmp(instr, "pb", 2) == 0)
		pb(s);
	else
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*s;
	int		i;
	char	*instr;

	if (argc < 2)
		return (-1);
	s = elaborate_input(argc, argv, &i);
	if (s == NULL)
		return (-1);
	instr = get_next_line(0);
	while (ft_strlen_2(instr) > 0)
	{
		if (elaborate_instruction(s, instr) == 0)
			break ;
		free(instr);
		instr = get_next_line(0);
	}
	write_result_and_free(s);
	return (0);
}
