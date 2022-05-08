#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include "../libft/libft.h"
#include <sys/time.h>

typedef struct s_routine
{
	int	tim_die;
	int	tim_eat;
	int	tim_slp;
	int	num_eat;
}	t_routine;

typedef struct s_seat
{
	pthread_t		philo;
	int				id;
	t_routine		routine;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
}	t_seat;

typedef struct s_table
{
	int				num_seats;
	t_seat			*seats;
	pthread_mutex_t	*forks;
	t_routine		routine;
}	t_table;

//src/system
void	clean(t_table *table);

//init
int		init_process(t_table *table, int argc, char *argv[]);

// threads
void	thread_creation(t_table *table);

//exec
void	*exec_philo(void *seat);

void	print_(t_table *table, int argc);
#endif