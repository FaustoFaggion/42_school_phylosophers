/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunch_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:38:15 by fausto            #+#    #+#             */
/*   Updated: 2022/07/19 12:26:23 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	msg(char *msg, t_seat *philo)
{
	long int	now;

	pthread_mutex_lock(philo->waiter);
	if (*(philo->die_flag) == 0)
	{
		now = get_now(philo);
		printf("%ld %d %s\n", now, philo->id, msg);
	}
	pthread_mutex_unlock(philo->waiter);
}

void	has_taken_a_fork(t_seat *philo)
{
	if (philo->id % 2 != 0)
	{
		pthread_mutex_lock(philo->fork_right);
		msg("has taken a fork", philo);
		pthread_mutex_lock(philo->fork_left);
		msg("has taken a fork", philo);
	}
	else
	{
		pthread_mutex_lock(philo->fork_left);
		msg("has taken a fork", philo);
		pthread_mutex_lock(philo->fork_right);
		msg("has taken a fork", philo);
	}
}

void	is_eating(t_seat *philo)
{
	philo->routine.last_meal = get_now(philo);
	msg("is eating", philo);
	usleep(philo->routine.tim_eat * 1000);
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
}

void	is_sleeping(t_seat *philo)
{
	msg("is sleeping", philo);
	usleep(philo->routine.tim_slp * 1000);
}

void	is_thinking(t_seat *philo)
{
	int	time_die;
	int	time_slp;
	int	time_eat;

	time_die = philo->routine.tim_die;
	time_slp = philo->routine.tim_slp;
	time_eat = philo->routine.tim_eat;
	msg("is thinking", philo);
	if (time_die - (time_eat + time_slp) > 10)
	{
		usleep(((time_die - (time_eat + time_slp)) * 1000) - (10 * 1000));
	}
}
