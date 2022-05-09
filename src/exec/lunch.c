/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 06:56:36 by fagiusep          #+#    #+#             */
/*   Updated: 2022/05/09 12:59:51 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	has_taken_a_fork(t_seat *philo);
static void	taken_fork(t_seat *philo, char c);
static void	is_eating(t_seat *philo);
static void	is_sleeping(t_seat *philo);
static void	is_thinking(t_seat *philo);
static void	leave_fork(t_seat *philo);

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
		printf("%d leave fork\n\n", philo->id);
		pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(philo->fork_right);
		is_sleeping(philo);
		is_thinking(philo);
	}
	return ((void *)0);
}

static void	leave_fork(t_seat *philo)
{
	long int	t;
	long int	now;
	
	t = get_time();
	now = t - philo->routine.start;
	printf("%ld %d is sleeping\n",now, philo->id);
	usleep(philo->routine.tim_slp * 1000);
}

static void	has_taken_a_fork(t_seat *philo)
{
	if (philo->id % 2 != 0)
	{
		pthread_mutex_lock(philo->fork_right);
		taken_fork(philo, 'L');
		pthread_mutex_lock(philo->fork_left);
		taken_fork(philo, 'R');
	}
	else
	{
		pthread_mutex_lock(philo->fork_left);
		taken_fork(philo, 'R');
		pthread_mutex_lock(philo->fork_right);
		taken_fork(philo, 'L');
	}
}

static void	taken_fork(t_seat *philo, char c)
{
	long int	t;
	long int	now;
	
	t = get_time();
	now = t - philo->routine.start;
	printf("%ld %d has taken a fork %c\n", now, philo->id, c);
	//printf("t: %ld start: %ld now: %ld %d has taken a fork %c\n", t, philo->routine.start, now, philo->id, c);
}

static void	is_eating(t_seat *philo)
{
	long int	t;
	long int	now;
	long int	die;
	
//	printf("%ld %d last meal\n",philo->routine.last_meal, philo->id);
	t = get_time();
	now = t - philo->routine.start;
	die = t - philo->routine.last_meal;
	printf("%ld %d die ...................................\n",die, philo->id);
	printf("%ld %d is eating\n",now, philo->id);
	usleep(philo->routine.tim_eat * 1000);
	philo->routine.last_meal = get_time();
}

static void	is_sleeping(t_seat *philo)
{
	long int	t;
	long int	now;
	
	t = get_time();
	now = t - philo->routine.start;
	printf("%ld %d is sleeping\n",now, philo->id);
	usleep(philo->routine.tim_slp * 1000);
}

static void	is_thinking(t_seat *philo)
{
	long int	now;

	now = get_now(philo);
	printf("%ld %d is thinking\n",now, philo->id);
	while (1)
	{
		now = get_time();
		if (now - philo->routine.last_meal < philo->routine.tim_eat - 50)
			break;
	}
}