#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include "../libft/libft.h"
#include <sys/time.h>

typedef struct s_routine
{
	long int	start;
	long int	last_meal;
	int			tim_die;
	int			tim_eat;
	int			tim_slp;
	int			num_eat;
}	t_routine;

typedef struct s_seat
{
	pthread_t		philo;
	int				id;
	int				*die_flag;
	int				stuffed_flag;
	t_routine		routine;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	pthread_mutex_t	*waiter;
}	t_seat;

typedef struct s_table
{
	int				num_seats;
	t_seat			*seats;
	pthread_mutex_t	*forks;
	t_routine		routine;
	pthread_mutex_t	waiter;
	int				die_flag;
}	t_table;

//src/system
void	clean(t_table *table);

//init
int		init_process(t_table *table, int argc, char *argv[]);

// threads
void	create_philo(t_table *table);


//exec
void	setup_table(t_table *table);
void	*lunch(void *seat);

//time
unsigned long int	get_time(void);
unsigned long int	get_now(t_seat *philo);



void	print_(t_table *table, int argc);
#endif