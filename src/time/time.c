#include "philosophers.h"


unsigned long long	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((unsigned long long)t.tv_sec * 1000
		+ (unsigned long long)t.tv_usec / 1000);
}

unsigned long long	get_now(t_seat *philo)
{
	long int	t;

	t = get_time();
	return (t - philo->routine.start);
}