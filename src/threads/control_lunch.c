/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_lunch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:41:23 by fausto            #+#    #+#             */
/*   Updated: 2022/05/13 12:48:06 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	control_lunch(t_table *table)
{
	long int	now;
    int			i;
    int			x;

	x = 0;
	while (table->die_flag == 0 && ++x < table->routine.num_eat)
	{	
		i = -1;
		usleep((table->routine.tim_die * 1000) + 500);
		now = get_now(&table->seats[0]);
		while (++i < table->num_seats)
		{
			if ((now - ((unsigned long int)table->seats[i].routine.last_meal))
				> (unsigned long int)table->routine.tim_die)
			{
				if (table->seats[i].stuffed_flag == 0)
				{
					pthread_mutex_lock(&table->waiter);
					table->die_flag = 1;
					pthread_mutex_unlock(&table->waiter);
					printf("%ld %d died\n", now, table->seats[i].id);
					break ;
				}
			}
		}
	}
}
