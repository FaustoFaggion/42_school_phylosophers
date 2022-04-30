#include "philosophers.h"

int	chk_args_(t_rules *rules, int argc, char *argv[])
{
	int		index;

	if (argc != 5 && argc != 6)
	{
		printf("Wrong number of arguments");
		return (1);
	}
	index = 0;
	(*rules).phi_num = ft_atoi(argv[++index]);
	(*rules).tim_die = ft_atoi(argv[++index]);
	(*rules).tim_eat = ft_atoi(argv[++index]);
	(*rules).tim_slp = ft_atoi(argv[++index]);
	if (argc == 6)
		(*rules).num_eat = ft_atoi(argv[++index]);
	return (0);
}