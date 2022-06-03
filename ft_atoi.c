/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:36:29 by gcucino           #+#    #+#             */
/*   Updated: 2022/06/03 16:28:01 by gcucino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_sign(const char *str, int *i)
{
	int	ret;

	ret = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			ret = -ret;
		(*i)++;
	}
	return (ret);
}

int	ft_atoi(const char *str, int *ret)
{
	int		i;
	int		sign;
	long	tmp;

	i = 0;
	tmp = 0;
	sign = parse_sign(str, &i);
	while (str[i] != 0)
	{
		if (str[i] >= '0' && str[i] <= '9' && i < 12)
		{
			tmp += str[i] - 48;
			if (str[i + 1] >= '0' && str[i + 1] <= '9')
				tmp *= 10;
			i++;
		}
		else
			return (0);
	}
	tmp *= sign;
	if (tmp < -2147483648 || tmp > 2147483647)
		return (0);
	(*ret) = (int) tmp;
	return (1);
}
