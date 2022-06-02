/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_lunch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:41:23 by fausto            #+#    #+#             */
/*   Updated: 2022/06/02 08:17:33 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	philo_killer(t_table *table, int i, unsigned long int now)
{
	pthread_mutex_lock(&table->waiter);
	table->die_flag = 1;
	pthread_mutex_unlock(&table->waiter);
	printf("%ld %d died\n", now, table->seats[i].id);
}

void	control_lunch(t_table *table)
{
	long int	now;
	int			i;

	while (1)
	{	
		usleep(500);
		if (table->die_flag == 1 || table->all_stuffed == table->num_seats)
			break ;
		i = -1;
		while (++i < table->num_seats)
		{
			now = get_now(&table->seats[0]);
			if ((now - ((unsigned long int)table->seats[i].routine.last_meal))
				> (unsigned long int)table->routine.tim_die)
			{
				if (*(table->seats[i].stuffed_flag) == 0)
				{
					philo_killer(table, i, now);
					break ;
				}
			}
		}
	}
}
