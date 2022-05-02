#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>


typedef struct s_rules
{
	int	tim_die;
	int	tim_eat;
	int	tim_slp;
	int	num_eat;
}	t_rules;

typedef struct s_phil
{
	pthread_t		seat;
	struct s_phil	*next;
	struct s_phil	*previus;
	t_rules			rules;
}	t_phil;

//src/system

int		chk_args(int argc, char *argv[]);
//int		init_process(t_phil *waiter, int argc, char *argv[]);

// threas

//void	threads_init(int num_phil);
#endif