#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include "../libft/libft.h"

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
	t_routine		routine;
//	pthread_mutex_t	mutex;
}	t_seat;

typedef struct s_table
{
	int			num_seats;
	t_seat		*seats_on_table;
	t_routine	routine;
}	t_table;

//src/system
int		init_process(t_table *table, int argc, char *argv[]);

// threas
pthread_t	thread_creation();

//void	threads_init(int num_phil);
#endif