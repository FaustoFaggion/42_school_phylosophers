/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:57:56 by fagiusep          #+#    #+#             */
/*   Updated: 2022/05/30 17:36:38 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	create_philo_bonus(t_table *table)
{
	unsigned int	i;
	int				pid;
//	sem_t			*smp;

//	sem_unlink("semaphore");
//	table->smp = sem_open("semaphore", O_CREAT, S_IRWXU, 1);
	i = -1;
	while (++i < table->num_seats)
	{
		table->seats->id = i + 1;
		pid = fork();
		if (pid < 0)
		{
			sem_unlink("/fork");
			sem_close(table->fork);
			return ;
		}
		else if (pid == 0)
		{
			lunch_bonus(table);
			clean_bonus(table);
			exit(0);
		}
	}
	
	i = -1;
	while (++i < table->num_seats)
		waitpid(pid, NULL, 0);
	sem_unlink("/fork");
	sem_close(table->fork);
}
