#include "philosophers.h"
/*
static void	*chk_philo(void *temp)
{
	t_table		*table;
	long int	t;
	long int	die;
	int			i;

	table = (t_table *)temp;
	while (1)
	{
		t = get_time();
		i = -1;
		while (++i < table->num_seats)
		{
			die = t - table->seats[i].routine.last_meal;
			if (die > table->routine.tim_die)
			{
				printf("%ld philosopher %d die!!\n",die, table->seats[i].id);
					exit(0);
			}
		}
	}
	return((void *)0);
}

void	create_waiter(t_table *table)
{
	if (pthread_create(&table->waiter, NULL, chk_philo,
		(void*)&table) != 0)
		return ;
	if (pthread_join(table->waiter, NULL) != 0)
			return ;
}
*/