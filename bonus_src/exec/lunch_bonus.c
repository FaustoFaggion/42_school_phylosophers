/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunch_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:41:19 by fausto            #+#    #+#             */
/*   Updated: 2022/05/31 15:46:20 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static void	kill_process(t_table *table, unsigned long int now)
{
	int	i;
	
	table->seats->die_flag = 1;
	printf("%ld %d died\n", now, table->seats->id);
	i = -1;
	while (++i < (int)table->num_seats)
		sem_post(table->dead);
}

static void	*grave_digger(void *arg)
{
	t_table		*table;
	long int	now;

	table = (t_table *)arg;
	while (1)
	{	
		if (table->seats->stuffed_flag == 1)
		{
			sem_post(table->dead);
			break ;
		}
		now = get_now(table->seats);
		if (((long int)now - (long int)(table->seats->routine.last_meal))
			> (long int)table->seats->routine.tim_die)
		{
			if (table->seats->stuffed_flag == 0)
			{
				kill_process(table, now);
				break ;
			}
		}
	}
	return ((void *)0);
}

void	*lunch_bonus(t_table *table)
{
	int	x;

	x = 0;
	pthread_create(&table->waiter, NULL, grave_digger, (void *)table);
	if (table->seats->id % 2 == 0)
		usleep(500);
	while (1)
	{
		//if (table->num_seats != 1)
		has_taken_a_fork_bonus(table);
//		else
//			has_taken_a_fork_one(philo);
		is_eating_bonus(table);
		is_sleeping_bonus(table);
		is_thinking_bonus(table);
		if (++x == table->seats->routine.num_eat || (*table->seats).die_flag == 1)
			break ;
	}
	(*table->seats).stuffed_flag = 1;
	return ((void *)0);
}

/*
static void	has_taken_a_fork_one(t_seat *philo)
{
	pthread_mutex_lock(philo->fork_left);
	msg("has taken a fork", philo);
}
*/