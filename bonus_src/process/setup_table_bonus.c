/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_table_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:45:44 by fausto            #+#    #+#             */
/*   Updated: 2022/06/02 07:58:39 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static void	*waiter(void *arg)
{
	t_table			*table;
	unsigned int	i;

	table = (t_table *)arg;
	i = 0;
	while (i < table->num_seats)
	{
		sem_wait(table->dead);
		i++;
	}
	i = -1;
	while (++i < table->num_seats)
		kill(table->pid[i], SIGKILL);
	return ((void *)0);
}

void	setup_table_bonus(t_table *table)
{
	table->seats->routine.start = get_time();
	table->seats->routine.last_meal = get_now(table->seats);
	create_philo_bonus(table);
	pthread_create(&table->waiter, NULL, waiter, (void *)table);
	pthread_join(table->waiter, NULL);
}
