/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:29:01 by fausto            #+#    #+#             */
/*   Updated: 2022/07/20 10:08:27 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	chk_args(int argc, char *argv[]);
static void	init_table(t_table *table, int argc, char *argv[]);
static void	init_table_seats(t_table *table);
static int	convert_to_number(int argc, char *argv[]);

int	init_process(t_table *table, int argc, char *argv[])
{
	if (chk_args(argc, argv) == 1)
		return (1);
	init_table(table, argc, argv);
	init_table_seats(table);
	if (table->num_seats > 1)
		init_table_forks(table);
	else
		init_table_forks_one(table);
	return (0);
}

static int	chk_args(int argc, char *argv[])
{

	if (argc != 5 && argc != 6)
	{
		write(2, "Wrong number of arguments!\n", 27);
		return (1);
	}
	if (convert_to_number(argc, argv) == 1)
		return (1);
	return (0);
}

static int	convert_to_number(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][0] == '-')
			{
				write(2, "Arguments must be a number greater than 0!\n", 43);
				return (1);
			}	
			if (ft_isdigit(argv[i][j]) == 0)
			{
				printf("argc: %d digit:%c", i, argv[i][j]);
				write(2, "Arguments must be a number!\n", 30);
				return (1);
			}
			j++;
		}
		ft_atoi(argv[i]);
	}
	return (0);
}

static void	init_table(t_table *table, int argc, char *argv[])
{
	table->num_seats = ft_atoi(argv[1]);
	table->routine.tim_die = ft_atoi(argv[2]);
	table->routine.tim_eat = ft_atoi(argv[3]);
	table->routine.tim_slp = ft_atoi(argv[4]);
	if (argc == 6)
		table->routine.num_eat = ft_atoi(argv[5]);
	else
		table->routine.num_eat = 0;
	table->routine.last_meal = 0;
	table->die_flag = 0;
	table->all_stuffed = 0;
	pthread_mutex_init(&table->waiter, NULL);
}

static void	init_table_seats(t_table *table)
{
	int	i;

	table->seats = NULL;
	table->seats = ft_calloc(table->num_seats + 1, sizeof(t_seat));
	i = -1;
	while (++i < table->num_seats)
	{
		table->seats[i].id = i + 1;
		table->seats[i].die_flag = &table->die_flag;
		table->seats[i].stuffed = &table->all_stuffed;
		table->seats[i].stuffed_flag = 0;
		table->seats[i].waiter = &table->waiter;
		table->seats[i].fork_left = NULL;
		table->seats[i].fork_right = NULL;
		table->seats[i].one_philo_only = table->num_seats;
	}
	i = -1;
	while (++i < table->num_seats)
	{
		table->seats[i].routine.tim_die = table->routine.tim_die;
		table->seats[i].routine.tim_eat = table->routine.tim_eat;
		table->seats[i].routine.tim_slp = table->routine.tim_slp;
		table->seats[i].routine.num_eat = table->routine.num_eat;
		table->seats[i].routine.last_meal = 0;
	}
}
