#include "philosophers.h"

/*
static void	debug(t_rules *rules)
{
	printf("tim_die: %d\n", rules->tim_die);
	printf("tim_eat: %d\n", rules->tim_eat);
	printf("tim_slp: %d\n", rules->tim_slp);
	printf("num_eat: %d\n", rules->num_eat);
}

static void	threads_init(int num_phil)
{
	int	i;

	i = 0;
	while (i < num_phil)
	{
		i++;
	}
}
*/


int	main(int argc, char *argv[])
{
	printf("HELLO\n");

	if (chk_args(argc, argv) == 1)
		return (1);

	return (0);
}