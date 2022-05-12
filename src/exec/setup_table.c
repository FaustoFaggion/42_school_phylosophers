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
}