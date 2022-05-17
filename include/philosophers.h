/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:26:09 by fausto            #+#    #+#             */
/*   Updated: 2022/05/17 13:16:04 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include "../libft/libft.h"
# include <sys/time.h>

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
	int				one_philo_only;
	int				id;
	int				*die_flag;
	int				*stuffed_flag;
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
	int				all_stuffed;
}	t_table;

//src/system
void				clean(t_table *table);

//init
int					init_process(t_table *table, int argc, char *argv[]);
void				init_table_forks(t_table *table);
void				init_table_forks_one(t_table *table);

// threads
void				setup_table(t_table *table);
void				create_philo(t_table *table);
void				control_lunch(t_table *table);
void				wait_and_destroy(t_table *table);

//exec
void				*lunch(void *seat);
void				msg(char *msg, t_seat *philo);
void				has_taken_a_fork(t_seat *philo);
void				is_eating(t_seat *philo);
void				is_sleeping(t_seat *philo);
void				is_thinking(t_seat *philo);

//time
unsigned long int	get_time(void);
unsigned long int	get_now(t_seat *philo);

void				print_(t_table *table, int argc);
#endif
