/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:36:29 by gcucino           #+#    #+#             */
/*   Updated: 2022/05/20 19:20:56 by gcucino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str, int *ret)
{
	int	i;
	int	sign;

	i = 0;
	(*ret) = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] != 0)
	{ 
		if (str[i] >= '0' && str[i] <= '9')
		{
			(*ret) += str[i] - 48;
			if (str[i + 1] >= '0' && str[i + 1] <= '9')
				(*ret) *= 10;
			i++;
		}
		else
			return (0);
	}
	
	(*ret) *= sign;
	return (1);
}
