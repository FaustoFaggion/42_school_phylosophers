/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_atoi_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 09:38:48 by fausto            #+#    #+#             */
/*   Updated: 2022/07/20 09:39:04 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\v' || c == '\r'
		|| c == '\n' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *ptr)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (ft_isspace(*ptr))
	{
		ptr++;
	}
	if (*ptr == '+' || *ptr == '-')
	{
		if (*ptr == '-')
			sign = -1;
		ptr++;
	}
	while (ft_isdigit(*ptr))
	{
		res = (res * 10) + (*ptr - 48);
		ptr++;
	}
	return (sign * res);
}
