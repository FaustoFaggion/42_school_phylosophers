/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunch_actions_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:38:15 by fausto            #+#    #+#             */
/*   Updated: 2022/05/30 12:45:06 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	msg_bonus(char *msg, t_table *table)
{
	long int	now;

	if (table->seats->die_flag == 0)
	{
		now = get_now(table->seats);
		printf("%ld %d %s\n", now, table->seats->id, msg);
		sleep(2);
	}
}

void	has_taken_a_fork_bonus(t_table *table)
{
	sem_wait(table->smp);
	sem_wait(table->smp);
	msg_bonus("has taken a fork", table);
	msg_bonus("has taken a fork", table);
}

void	is_eating(t_table *table)
{
	table->seats->routine.last_meal = get_now(table->seats);
	msg_bonus("is eating", table);
	usleep(table->seats->routine.tim_eat * 1000);
//	if (philo->one_philo_only != 1)
//		pthread_mutex_unlock(philo->fork_right);
	sem_post(table->smp);
	sem_post(table->smp);
}
/*
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