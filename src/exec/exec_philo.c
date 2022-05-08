/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 06:56:36 by fagiusep          #+#    #+#             */
/*   Updated: 2022/05/08 12:25:16 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	taken_fork(t_seat *philo);

void	*exec_philo(void *seat)
{
	int		x;
	t_seat	*philo;

	philo = (t_seat *)seat;
	x = -1;
	while (++x < 2)
	{
		pthread_mutex_lock(philo->fork_left);
		taken_fork(philo);
		pthread_mutex_lock(philo->fork_right);
		taken_fork(philo);
		printf("timestamp %d is eating\n", philo->id);
		usleep(philo->routine.tim_eat * 1000);

		pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(philo->fork_right);
		printf("timestamp %d finish eating\n", philo->id);
	}
	return ((void *)0);
}

static void	taken_fork(t_seat *philo)
{
	int	t;

	t = get_time();
	printf("%d %d has taken a fork\n", t, philo->id);
}