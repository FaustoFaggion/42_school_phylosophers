#include "philosophers.h"

static int	chk_args(int argc, char *argv[]);
static void	fill_routine(t_table *table, int argc, char *argv[]);

int	init_process(t_table *table, int argc, char *argv[])
{
	if (chk_args(argc, argv) == 1)
		return (1);
	fill_routine(table, argc, argv);
	
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
		if (ft_isdigit((*argv)[i]))
		{
			write(2, "Arguments must be a number!\n", 30);
			return (1);
		}

		if (ft_atoi(argv[i]) <= 0)
		{
			write(2, "Arguments must be a number greater than 0!\n", 43);
			return (1);
		}
	}
	return (0);
}

static void	fill_routine(t_table *table, int argc, char *argv[])
{
	table->num_seats = ft_atoi(argv[1]);
	table->routine.tim_die = ft_atoi(argv[2]);
	table->routine.tim_eat = ft_atoi(argv[3]);
	table->routine.tim_slp = ft_atoi(argv[4]);
	if (argc == 8)
		table->routine.num_eat = ft_atoi(argv[5]);
}