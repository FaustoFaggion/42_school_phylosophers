/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunch_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:41:19 by fausto            #+#    #+#             */
/*   Updated: 2022/07/13 10:54:33 by fausto           ###   ########.fr       */
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
		usleep(500);
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

static void	has_taken_a_fork_one_bonus(t_table *table)
{
	int			time_die;
	long int	now;

	time_die = table->seats->routine.tim_die;
	msg_bonus("has taken a fork", table);
	usleep(time_die * 1000);
	now = get_now(table->seats);
	kill_process(table, now);
}

static int	taken_fork(t_table *table)
{
	if (table->num_seats != 1)
		has_taken_a_fork_bonus(table);
	else
	{
		has_taken_a_fork_one_bonus(table);
		return (1);
	}
	return (0);
}

void	*lunch_bonus(t_table *table)
{
	int	x;
	int	num_eat;
	int	die_flag;

	num_eat = table->seats->routine.num_eat;
	die_flag = table->seats->die_flag;
	x = 0;
	pthread_create(&table->grave_digger, NULL, grave_digger, (void *)table);
	if (table->seats->id % 2 == 0)
		usleep(500);
	while (1)
	{
		if (taken_fork(table) == 1)
			break ;
		is_eating_bonus(table);
		is_sleeping_bonus(table);
		is_thinking_bonus(table);
		if (++x == num_eat || die_flag == 1)
			break ;
	}
	(*table->seats).stuffed_flag = 1;
	return ((void *)0);
}
