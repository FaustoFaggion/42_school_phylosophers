/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_calloc_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 09:39:10 by fausto            #+#    #+#             */
/*   Updated: 2022/07/20 09:39:13 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	ft_bzero(void *s, size_t n)
{
	while (n > 0)
	{
		*((char *)s) = 0;
		s++;
		n--;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	*pos;
	size_t	tot_size;

	tot_size = nmemb * size;
	pos = malloc(tot_size);
	if (!pos || (tot_size > INT_MAX))
		return (NULL);
	ft_bzero(pos, tot_size);
	return ((void *)pos);
}
