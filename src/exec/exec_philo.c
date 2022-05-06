/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 06:56:36 by fagiusep          #+#    #+#             */
/*   Updated: 2022/05/06 07:46:32 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*exec_philo(void *seat)
{
	int		x;
	t_seat	*philo;

	philo = (t_seat *)seat;
	start_routine(&philo->routine);
	x = -1;
	while (++x < 2)
	{
		pthread_mutex_lock(philo->fork_left);
		pthread_mutex_lock(philo->fork_right);

		printf("timestamp %d has taken a fork\n", philo->id);
		printf("timestamp %d is eating\n", philo->id);
		usleep(philo->routine.tim_eat * 1000);

		pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(philo->fork_right);
		printf("timestamp %d finish eating\n", philo->id);
	}
	return ((void *)0);
}
