#include "philosophers.h"

void	init_table_routine(t_table *table, int argc, char *argv[])
{
	table->num_seats = ft_atoi(argv[1]);
	table->routine.tim_die = ft_atoi(argv[2]);
	table->routine.tim_eat = ft_atoi(argv[3]);
	table->routine.tim_slp = ft_atoi(argv[4]);
	if (argc == 6)
		table->routine.num_eat = ft_atoi(argv[5]);
	else
		table->routine.num_eat = 0;
}