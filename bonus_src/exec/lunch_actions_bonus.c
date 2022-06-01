/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunch_actions_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:42:40 by fausto            #+#    #+#             */
/*   Updated: 2022/06/01 20:17:55 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	msg_bonus(char *msg, t_table *table)
{
	long int	now;

	sem_wait(table->msg);
	now = get_now(table->seats);
	printf("%ld %d %s\n", now, table->seats->id, msg);
	sem_post(table->msg);
}

void	has_taken_a_fork_bonus(t_table *table)
{
	sem_wait(table->fork);
	if (table->num_seats > 1)
		sem_wait(table->fork);
	msg_bonus("has taken a fork", table);
	if (table->num_seats > 1)
		msg_bonus("has taken a fork", table);
}

void	is_eating_bonus(t_table *table)
{
	table->seats->routine.last_meal = get_now(table->seats);
	msg_bonus("is eating", table);
	usleep(table->seats->routine.tim_eat * 1000);
	sem_post(table->fork);
	if (table->num_seats > 1)
		sem_post(table->fork);
}

void	is_sleeping_bonus(t_table *table)
{
	msg_bonus("is sleeping", table);
	usleep(table->seats->routine.tim_slp * 1000);
}

void	is_thinking_bonus(t_table *table)
{
	int	time_die;
	int	time_slp;
	int	time_eat;
	
	time_die = table->seats->routine.tim_die;
	time_slp = table->seats->routine.tim_slp;
	time_eat = table->seats->routine.tim_eat;
	msg_bonus("is thinking", table);
	if (time_die - (time_eat + time_slp) > 1000)
		usleep(((time_die - (time_eat + time_slp)) * 1000) - 500);
}
