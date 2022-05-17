/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_lunch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:41:23 by fausto            #+#    #+#             */
/*   Updated: 2022/05/17 13:20:36 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	control_lunch(t_table *table)
{
	long int	now;
	int			i;

	while (1)
	{	
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
