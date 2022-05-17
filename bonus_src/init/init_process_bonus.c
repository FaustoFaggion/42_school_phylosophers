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
	int	i;

	table->seats = NULL;
	table->seats = ft_calloc(table->num_seats + 1, sizeof(t_seat));
	i = -1;
	while (++i < table->num_seats)
	{
		table->seats[i].id = i + 1;
		table->seats[i].die_flag = &table->die_flag;
		table->seats[i].stuffed_flag = 0;
		table->seats[i].waiter = &table->waiter;
	}
	i = -1;
	while (++i < table->num_seats)
	{
		table->seats[i].routine.tim_die = table->routine.tim_die;
		table->seats[i].routine.tim_eat = table->routine.tim_eat;
		table->seats[i].routine.tim_slp = table->routine.tim_slp;
		table->seats[i].routine.num_eat = table->routine.num_eat;
		table->seats[i].routine.last_meal = 0;
	}
}

static void	init_table_forks(t_table *table)
{
	int	i;

	table->forks = NULL;
	table->forks = ft_calloc(table->num_seats + 1, sizeof(pthread_mutex_t));
	i = -1;
	while (++i < table->num_seats)
		pthread_mutex_init(&table->forks[i], NULL);
	i = -1;
	while (++i < table->num_seats)
	{
		if (i + 1 == table->num_seats)
		{
			table->seats[i].fork_right = &table->forks[i];
			table->seats[i].fork_left = &table->forks[0];
			table->seats[i].routine.tim_eat = table->routine.tim_eat;
		}
		else
		{
			table->seats[i].fork_right = &table->forks[i];
			table->seats[i].fork_left = &table->forks[i + 1];
			table->seats[i].routine.tim_eat = table->routine.tim_eat;
		}
	}
}
