/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 06:56:36 by fagiusep          #+#    #+#             */
/*   Updated: 2022/07/18 12:28:19 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	has_taken_a_fork_one(t_seat *philo);

void	*lunch(void *seat)
{
	int		x;
	t_seat	*philo;

	philo = (t_seat *)seat;
	if (philo->id % 2 == 0)
		usleep(500);
	x = 0;
	while (1)
	{
		if (philo->one_philo_only != 1)
			has_taken_a_fork(philo);
		else
		{
			has_taken_a_fork_one(philo);
			break ;
		}
		is_eating(philo);
		is_sleeping(philo);
		is_thinking(philo);
		if (++x == philo->routine.num_eat || *(philo->die_flag) == 1)
			break ;
	}
	*(philo->stuffed) += 1;
	philo->stuffed_flag = 1;
	return ((void *)0);
}

static void	has_taken_a_fork_one(t_seat *philo)
{
	long int	now;

	pthread_mutex_lock(philo->fork_left);
	msg("has taken a fork", philo);
	usleep(philo->routine.tim_die * 1000);
	now = get_now(philo);
	*philo->die_flag = 1;
	printf("%ld %d died\n", now, philo->id);
}
