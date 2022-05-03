#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_routine
{
	int	num_phil;
	int	tim_die;
	int	tim_eat;
	int	tim_slp;
	int	num_eat;
}	t_routine;

typedef struct s_phil
{
	pthread_t		philo;
	t_routine		routine;
//	pthread_mutex_t	mutex;
}	t_phil;

//src/system
int		init_process(t_routine *routine, int argc, char *argv[]);

// threas
pthread_t	thread_creation();

//void	threads_init(int num_phil);
#endif