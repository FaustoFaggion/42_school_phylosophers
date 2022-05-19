/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:57:56 by fagiusep          #+#    #+#             */
/*   Updated: 2022/05/19 10:53:40 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	create_philo(t_table *table)
{
	int	i;
	int	*pid;

	pid = ft_calloc(table->num_seats, sizeof(int));
	i = -1;
	while (++i < table->num_seats)
	{
		pid[i] = fork();
		if (pid[i] < 0)
			return ;
		if (pid[i] == 0)
		{
			printf("25 - pid[%d]: %d\n", i, pid[i]);
			exit(0);
		}
	}
	i = -1;
	while (++i < table->num_seats)
		waitpid(pid[i], NULL, 0);
}
