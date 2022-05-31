#include "philosophers_bonus.h"

static int	chk_args(int argc, char *argv[]);
static void	init_table(t_table *table, char *argv[]);
static void	init_table_seats(t_table *table, int argc, char *argv[]);

int	init_process_bonus(t_table *table, int argc, char *argv[])
{
	if (chk_args(argc, argv) == 1)
		return (1);
	init_table(table, argv);
	init_table_seats(table, argc, argv);
	return (0);
}

static int	chk_args(int argc, char *argv[])
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

static void	init_table(t_table *table, char *argv[])
{
	table->num_seats = ft_atoi(argv[1]);
	table->seats = ft_calloc(1, sizeof(t_seat));
	table->pid = ft_calloc(table->num_seats, sizeof(pid_t));
	sem_unlink("/fork");
	table->fork = sem_open("/fork", O_CREAT, S_IRWXU, table->num_seats);
	sem_unlink("/dead");
	table->dead = sem_open("/dead", O_CREAT, S_IRWXU, 0);
	sem_unlink("/msg");
	table->msg = sem_open("/msg", O_CREAT, S_IRWXU, 1);
}

static void	init_table_seats(t_table *table, int argc, char *argv[])
{
	table->seats->id = 1;
	table->seats->die_flag = 0;
	table->seats->stuffed_flag = 0;
	table->seats->routine.tim_die = ft_atoi(argv[2]);
	table->seats->routine.tim_eat = ft_atoi(argv[3]);
	table->seats->routine.tim_slp =  ft_atoi(argv[4]);
	if (argc == 6)
		table->seats->routine.num_eat = ft_atoi(argv[5]);
	else 
		table->seats->routine.num_eat = -1;
	table->seats->routine.last_meal = 0;
}
