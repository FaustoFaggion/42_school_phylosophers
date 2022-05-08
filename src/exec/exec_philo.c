/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 06:56:36 by fagiusep          #+#    #+#             */
/*   Updated: 2022/05/08 19:57:50 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	taken_fork(t_seat *philo, char c);
static void	is_eating(t_seat *philo);

void	*exec_philo(void *seat)
{
	int		x;
	t_seat	*philo;

	philo = (t_seat *)seat;
	x = -1;
	while (++x < 2)
	{
		pthread_mutex_lock(philo->fork_left);
		taken_fork(philo, 'L');
		pthread_mutex_lock(philo->fork_right);
		taken_fork(philo, 'R');
		is_eating(philo);
		printf("%d finish eating 0\n", philo->id);
		
		pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(philo->fork_right);
		printf("%d leave fork\n\n", philo->id);
		
		usleep(philo->routine.tim_slp);
	}
	return ((void *)0);
}

static void	taken_fork(t_seat *philo, char c)
{
	long int	t;
	long int	now;
	
	t = get_time();
	now = t - philo->routine.start;
	printf("t: %ld start: %ld now: %ld %d has taken a fork %c\n", t, philo->routine.start, now, philo->id, c);
}

static void	is_eating(t_seat *philo)
{
	long int	t;
	long int	now;
	
	printf("%ld %d last meal\n",philo->routine.last_meal, philo->id);
	t = get_time();
	now = t - philo->routine.start;
	philo->routine.last_meal = now;
	printf("%ld %d is eating\n",now, philo->id);
	usleep(philo->routine.tim_eat * 1000);
}