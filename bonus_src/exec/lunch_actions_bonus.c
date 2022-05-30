/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunch_actions_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:38:15 by fausto            #+#    #+#             */
/*   Updated: 2022/05/30 15:50:03 by fausto           ###   ########.fr       */
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

void	is_sleeping(t_table *table)
{
	msg_bonus("is sleeping", table);
	usleep(table->seats->routine.tim_slp * 1000);
}

void	is_thinking(t_table *table)
{
	msg_bonus("is thinking", table);
	if (table->seats->routine.tim_die > table->seats->routine.tim_slp + 1)
		usleep(table->seats->routine.tim_die - (table->seats->routine.tim_slp + 1));
}
