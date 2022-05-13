/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_and_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:44:18 by fausto            #+#    #+#             */
/*   Updated: 2022/05/13 12:44:44 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	wait_and_destroy(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->num_seats)
	{
		if (pthread_join(table->seats[i].philo, NULL) != 0)
			return ;
	}
	i = -1;
	while (++i < table->num_seats)
		pthread_mutex_destroy(&table->forks[i]);
	pthread_mutex_destroy(&table->waiter);
}
