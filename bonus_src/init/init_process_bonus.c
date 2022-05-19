#include "philosophers_bonus.h"

static int	chk_args(int argc, char *argv[]);
static void	init_table(t_table *table, int argc, char *argv[]);
static void	init_table_seats(t_table *table);
static void	init_table_forks(t_table *table);

int	init_process(t_table *table, int argc, char *argv[])
{
	if (chk_args(argc, argv) == 1)
		return (1);
	init_table(table, argc, argv);
	init_table_seats(table);
	init_table_forks(table);
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

static void	init_table(t_table *table, int argc, char *argv[])
{
	table->num_seats = ft_atoi(argv[1]);
	table->routine.tim_die = ft_atoi(argv[2]);
	table->routine.tim_eat = ft_atoi(argv[3]);
	table->routine.tim_slp = ft_atoi(argv[4]);
	if (argc == 6)
		table->routine.num_eat = ft_atoi(argv[5]);
	else
		table->routine.num_eat = -1;
	table->routine.last_meal = 0;
	table->die_flag = 0;
	pthread_mutex_init(&table->waiter, NULL);
}

static void	init_table_seats(t_table *table)
{
	table->seats = NULL;
	table->seats = ft_calloc(1, sizeof(t_seat));
	table->seats->id = 1;
	table->seats->die_flag = &table->die_flag;
	table->seats->stuffed_flag = 0;
	table->seats->waiter = &table->waiter;
	table->seats->routine.tim_die = table->routine.tim_die;
	table->seats->routine.tim_eat = table->routine.tim_eat;
	table->seats->routine.tim_slp = table->routine.tim_slp;
	table->seats->routine.num_eat = table->routine.num_eat;
	table->seats->routine.last_meal = 0;
}

static void	init_table_forks(t_table *table)
{
	sem_t	semap;

	sem_init(&semap, 1, table->num_seats / 2);
	printf("semaphores: %d\n", table->num_seats / 2);
}