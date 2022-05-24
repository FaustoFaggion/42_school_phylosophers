/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunch_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 06:56:36 by fagiusep          #+#    #+#             */
/*   Updated: 2022/05/24 13:52:52 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

//static void	has_taken_a_fork_one(t_seat *philo);

void	*lunch(t_table *table)
{
//	while (1)
//	{
		printf("philo[%d] start lunch!!\n", table->seats->id);
		//if (table->num_seats != 1)
		has_taken_a_fork(table);
//		else
//			has_taken_a_fork_one(philo);
//		is_eating(philo);
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