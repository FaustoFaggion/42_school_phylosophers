#include "philosophers.h"

static void	print_(t_table *table, int argc)
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

	if (init_process(&table, argc, argv) == 1)
		return (1);
	thread_creation();
	print_(&table, argc);
//	pthread_exit;
	return (0);
}
