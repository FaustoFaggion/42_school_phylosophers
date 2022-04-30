#include "philosophers.h"

static void	debug(t_rules *rules)
{
	printf("phi_num: %d\n", rules->phi_num);
	printf("tim_die: %d\n", rules->tim_die);
	printf("tim_eat: %d\n", rules->tim_eat);
	printf("tim_slp: %d\n", rules->tim_slp);
	printf("num_eat: %d\n", rules->num_eat);
}
int	main(int argc, char *argv[])
{
	t_rules	rules;

	if (chk_args_(&rules, argc, argv) == 1)
		return (1);

	debug(&rules);
	return (0);
}