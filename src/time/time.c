/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:47:04 by fausto            #+#    #+#             */
/*   Updated: 2022/05/13 12:47:22 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

unsigned long int	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((unsigned long long)t.tv_sec * 1000
		+ (unsigned long long)t.tv_usec / 1000);
}

unsigned long int	get_now(t_seat *philo)
{
	long int	t;

	t = get_time();
	return (t - philo->routine.start);
}
