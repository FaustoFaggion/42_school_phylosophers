#include "philosophers_bonus.h"

void	print_(t_table *table, int argc)
{
	printf("num_philo: %d\n", table->num_seats);
	printf("tim_die: %d\n", table->seats->routine.tim_die);
	printf("tim_eat: %d\n", table->seats->routine.tim_eat);
	printf("tim_slp: %d\n", table->seats->routine.tim_slp);
	if (argc == 8)
		printf("num_eat: %d\n", table->seats->routine.num_eat);
}

int	main(int argc, char *argv[])
{
	t_table			table;
	unsigned int	i;

	if (init_process_bonus(&table, argc, argv) == 1)
		return (1);
	setup_table_bonus(&table);
	i = -1;
	while (++i < table.num_seats)
		waitpid(table.pid[i], NULL, 0);
	sem_unlink("/fork");
	sem_close(table.fork);
	sem_unlink("/dead");
	sem_close(table.dead);
	sem_unlink("/msg");
	sem_close(table.msg);
//	control_lunch(&table);
//	wait_and_destroy(&table);
	clean_bonus(&table);
	return (0);
}
