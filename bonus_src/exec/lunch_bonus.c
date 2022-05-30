/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunch_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 06:56:36 by fagiusep          #+#    #+#             */
/*   Updated: 2022/05/30 15:38:05 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static void	*waiter(void *arg)
{
	t_seat		*seat;
	long int	now;

	seat = (t_seat *)arg;
	seat->die_flag = 0;
	while (1)
	{	
		if (seat->stuffed_flag == 1)
			break ;
		now = get_now(seat);
		if ((now - ((unsigned long int)seat->routine.last_meal))
			> (unsigned long int)seat->routine.tim_die)
		{
			if (seat->stuffed_flag == 0)
			{
				seat->die_flag = 1;
				printf("%ld %d died\n", now, seat->id);
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
	pthread_create(&table->waiter, NULL, waiter, (void *)table->seats);
	if (table->seats->id % 2 == 0)
		usleep((table->seats->routine.tim_die * 1000));
	while (1)
	{
//		printf("philo[%d] start lunch!!\n", table->seats->id);
		//if (table->num_seats != 1)
		has_taken_a_fork_bonus(table);
//		else
//			has_taken_a_fork_one(philo);
		is_eating(table);
		is_sleeping(table);
		is_thinking(table);
		if (++x == table->seats->routine.num_eat) //|| *(philo->seats.die_flag) == 1)
			break ;
	}
//	*(philo->seats.stuffed_flag) += 1;
	return ((void *)0);
}

/*
static void	has_taken_a_fork_one(t_seat *philo)
{
	pthread_mutex_lock(philo->fork_left);
	msg("has taken a fork", philo);
}
*/