#include "philosophers.h"

static int	chk_args(int argc, char *argv[]);
static void	fill_routine(t_routine *routine, int argc, char *argv[]);

int	init_process(t_routine *routine, int argc, char *argv[])
{
	if (chk_args(argc, argv) == 1)
		return (1);
	fill_routine(routine, argc, argv);
	
	return (0);
}

int		chk_args(int argc, char *argv[])
{
	int	i;

	if (argc != 5 && argc != 6)
	{
		write(2, "Wrong number of arguments!\n", 27);
		return (1);
	}
	i = 0;
	while (++i < argc)
	{
		if (ft_atoi(argv[i]) <= 0)
		{
			write(2, "Arguments must be greater than 0!\n", 33);
			return (1);
		}
	}
	return (0);
}

static void	fill_routine(t_routine *routine, int argc, char *argv[])
{
	routine->num_phil = ft_atoi(argv[1]);
	routine->tim_die = ft_atoi(argv[2]);
	routine->tim_eat = ft_atoi(argv[3]);
	routine->tim_slp = ft_atoi(argv[4]);
	if (argc == 8)
		routine->num_eat = ft_atoi(argv[5]);
}