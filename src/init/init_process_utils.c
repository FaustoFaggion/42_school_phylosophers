/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_process_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:17:36 by fausto            #+#    #+#             */
/*   Updated: 2022/05/17 13:18:37 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_table_forks(t_table *table)
{
	int	i;

	table->forks = NULL;
	table->forks = ft_calloc(table->num_seats + 1, sizeof(pthread_mutex_t));
	i = -1;
	while (++i < table->num_seats)
		pthread_mutex_init(&table->forks[i], NULL);
	i = -1;
	while (++i < table->num_seats)
	{
		if (i + 1 == table->num_seats)
		{
			table->seats[i].fork_right = &table->forks[i];
			table->seats[i].fork_left = &table->forks[0];
		}
		else
		{
			table->seats[i].fork_right = &table->forks[i];
			table->seats[i].fork_left = &table->forks[i + 1];
		}
	}
}

void	init_table_forks_one(t_table *table)
{
	int	i;

	table->forks = NULL;
	table->forks = ft_calloc(table->num_seats + 1, sizeof(pthread_mutex_t));
	i = -1;
	while (++i < table->num_seats)
		pthread_mutex_init(&table->forks[i], NULL);
	table->seats[0].fork_left = &table->forks[0];
}
