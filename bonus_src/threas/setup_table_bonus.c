/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:45:44 by fausto            #+#    #+#             */
/*   Updated: 2022/05/13 12:46:06 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	setup_table(t_table *table)
{
	int	i;

	table->routine.start = get_time();
	i = -1;
	while (++i < table->num_seats)
	{
		table->seats[i].routine.start = table->routine.start;
		table->seats[i].routine.last_meal = get_now(&table->seats[i]);
	}
	create_philo(table);
}
