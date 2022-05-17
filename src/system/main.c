/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:46:24 by fausto            #+#    #+#             */
/*   Updated: 2022/05/16 15:20:42 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_(t_table *table, int argc)
{
	printf("num_philo: %d\n", table->num_seats);
	printf("tim_die: %d\n", table->routine.tim_die);
	printf("tim_eat: %d\n", table->routine.tim_eat);
	printf("tim_slp: %d\n", table->routine.tim_slp);
	if (argc == 8)
		printf("num_eat: %d\n", table->routine.num_eat);
}

int	main(int argc, char *argv[])
{
	t_table	table;

	setbuf(stdout, NULL);
	if (init_process(&table, argc, argv) == 1)
		return (1);
	setup_table(&table);
	control_lunch(&table);
	wait_and_destroy(&table);
	clean(&table);
	return (0);
}
