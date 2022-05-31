/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:39:54 by fausto            #+#    #+#             */
/*   Updated: 2022/05/31 15:40:03 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	create_philo_bonus(t_table *table)
{
	unsigned int	i;

	i = -1;
	while (++i < table->num_seats)
	{
		table->seats->id = i + 1;
		table->pid[i] = fork();
		if (table->pid[i] < 0)
		{
			sem_unlink("/fork");
			sem_close(table->fork);
			return ;
		}
		else if (table->pid[i] == 0)
		{
			lunch_bonus(table);
			clean_bonus(table);
			exit(0);
		}
	}
}
