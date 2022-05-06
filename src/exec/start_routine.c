#include "philosophers.h"

void	start_routine(t_routine *routine)
{
	routine->tim_die = timestamp();
	routine->tim_eat = timestamp();
	routine->tim_slp = timestamp();
}