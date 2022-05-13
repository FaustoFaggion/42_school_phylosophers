/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 06:56:36 by fagiusep          #+#    #+#             */
/*   Updated: 2022/05/13 12:38:09 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*lunch(void *seat)
{
	int		x;
	t_seat	*philo;

	philo = (t_seat *)seat;
	if (philo->id % 2 == 0)
		usleep(90); // definr de acordo com o numero de philosophers.
	x = -1;
	while (++x < philo->routine.num_eat || philo->die_flag == 0)
	{
		has_taken_a_fork(philo);
		is_eating(philo);
		is_sleeping(philo);
		is_thinking(philo);
	}
	philo->stuffed_flag = 1;
	return ((void *)0);
}
