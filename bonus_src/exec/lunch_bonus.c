/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunch_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 06:56:36 by fagiusep          #+#    #+#             */
/*   Updated: 2022/05/25 09:48:37 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

//static void	has_taken_a_fork_one(t_seat *philo);

void	*lunch_bonus(t_table *table)
{
	if (table->seats->id % 2 == 0)
		usleep((table->seats->routine.tim_die * 1000));
//	while (1)
//	{
//		printf("philo[%d] start lunch!!\n", table->seats->id);
		//if (table->num_seats != 1)
		has_taken_a_fork_bonus(table);
//		else
//			has_taken_a_fork_one(philo);
		is_eating(table);
//		is_sleeping(philo);
//		is_thinking(philo);
//		if (++x == philo->seats.routine.num_eat || *(philo->seats.die_flag) == 1)
//			break ;
//	}
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