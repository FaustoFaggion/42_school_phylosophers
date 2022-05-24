/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_table_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:45:44 by fausto            #+#    #+#             */
/*   Updated: 2022/05/24 14:11:57 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	setup_table(t_table *table)
{
	table->seats->routine.start = get_time();
	table->seats->routine.last_meal = get_now(&table->seats);
	printf("setup_table!!\n");
	create_philo(table);
}
