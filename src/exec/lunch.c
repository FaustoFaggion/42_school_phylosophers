/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 06:56:36 by fagiusep          #+#    #+#             */
/*   Updated: 2022/05/10 17:54:57 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	has_taken_a_fork(t_seat *philo);
static void	taken_fork(t_seat *philo);
static void	is_eating(t_seat *philo);
static void	is_sleeping(t_seat *philo);
static void	is_thinking(t_seat *philo);
static void	leave_fork(t_seat *philo);
static void	msg(char *msg, t_seat *philo);

void	*lunch(void *seat)
{
	int		x;
	t_seat	*philo;

	philo = (t_seat *)seat;
	if (philo->id % 2 == 0)
		usleep(500);
	
	x = -1;
	while (++x < philo->routine.num_eat)
	{
		has_taken_a_fork(philo);
		is_eating(philo);
		leave_fork(philo);
		pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(philo->fork_right);
		is_sleeping(philo);
		is_thinking(philo);
	}
	return ((void *)0);
}

static void	leave_fork(t_seat *philo)
{
	msg("leave fork\n",philo);
	usleep(philo->routine.tim_slp * 1000);
}

static void	msg(char *msg, t_seat *philo)
{
	long int	t;
	long int	now;
	
	t = get_time();
	now = t - philo->routine.start;
	printf("%ld %d %s\n", now, philo->id, msg);
}

static void	has_taken_a_fork(t_seat *philo)
{
	if (philo->id % 2 != 0)
	{
		pthread_mutex_lock(philo->fork_right);
		taken_fork(philo);
		pthread_mutex_lock(philo->fork_left);
		taken_fork(philo);
	}
	else
	{
		pthread_mutex_lock(philo->fork_left);
		taken_fork(philo);
		pthread_mutex_lock(philo->fork_right);
		taken_fork(philo);
	}
}

static void	taken_fork(t_seat *philo)
{	
	msg("has taken a fork\n", philo);
}

static void	is_eating(t_seat *philo)
{
	long int	t;
//	long int	now;
	long int	die;

	t = get_time();
//	now = t - philo->routine.start;
	die = t - philo->routine.last_meal;
	printf("%ld %d die ...................................\n",die, philo->id);
	msg("is eating\n", philo);
	usleep(philo->routine.tim_eat * 1000);
	philo->routine.last_meal = get_time();
}

static void	is_sleeping(t_seat *philo)
{
	msg("is sleeping\n", philo);
	usleep(philo->routine.tim_slp * 1000);
}

static void	is_thinking(t_seat *philo)
{
	long int	now;

	now = get_now(philo);
	msg("is thinking\n",philo);
	while (1)
	{
		now = get_time();
		if (now - philo->routine.last_meal < philo->routine.tim_eat - 50)
			break;
	}
}