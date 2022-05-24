/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunch_actions_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:38:15 by fausto            #+#    #+#             */
/*   Updated: 2022/05/24 17:51:52 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	msg_bonus(char *msg, t_table *table)
{
	long int	now;

//	pthread_mutex_lock(&table->waiter);
//	if (table->seats->die_flag == 0)
//	{
		now = get_now(table->seats);
		printf("%ld %d %s\n", now, table->seats->id, msg);
		sleep(2);
//	}
//	pthread_mutex_unlock(&table->waiter);
}

void	has_taken_a_fork_bonus(t_table *table)
{
//	printf("philo[%d] taken_fork\n", table->seats->id);
	sem_wait(table->smp);
	sleep(1);
	printf("enter the semaphore\n");
//	msg_bonus("has taken a fork", table);
	sem_post(table->smp);
//	sem_wait(table->semap);
//	msg("has taken a fork", table);
}
/*
void	is_eating(t_seat *philo)
{
	philo->routine.last_meal = get_now(philo);
	msg("is eating", philo);
	usleep(philo->routine.tim_eat * 1000);
	pthread_mutex_unlock(philo->fork_left);
	if (philo->one_philo_only != 1)
		pthread_mutex_unlock(philo->fork_right);
}

void	is_sleeping(t_seat *philo)
{
	msg("is sleeping", philo);
	usleep(philo->routine.tim_slp * 1000);
}

void	is_thinking(t_seat *philo)
{
	msg("is thinking", philo);
	if (philo->routine.tim_die > philo->routine.tim_slp + 1)
		usleep(philo->routine.tim_die - (philo->routine.tim_slp + 1));
}
*/