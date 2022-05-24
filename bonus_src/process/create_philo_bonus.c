/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:57:56 by fagiusep          #+#    #+#             */
/*   Updated: 2022/05/24 13:57:34 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	create_philo(t_table *table)
{
	unsigned int	i;
	int				pid;

	table->smp = sem_open("semaphore", O_CREAT, S_IRWXU, 1);
	i = -1;
	while (++i < table->num_seats)
	{
		table->seats->id = i + 1;
		pid = fork();
		if (pid < 0)
		{
		//	sem_unlink(semaphore);
//			sem_close(table->semap);
			return ;
		}
		else if (pid == 0)
			break ;
	//	printf("create philo[%d]!!\n", table->seats.id);//	
	}
	if (pid == 0)
	{
		lunch(table);
//		printf("25 - pid[%d]: %d id: %d\n", i, pid[i], table->seats.id);
		exit(0);
	}
	i = -1;
	while (++i < table->num_seats)
		waitpid(pid, NULL, 0);
//	fr(*table)d);
}
