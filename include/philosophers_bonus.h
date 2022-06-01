/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:26:09 by fausto            #+#    #+#             */
/*   Updated: 2022/06/01 20:21:28 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <pthread.h>
# include <stdio.h>
# include "../libft/libft.h"
# include <sys/time.h>
# include <sys/wait.h>
# include <semaphore.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/stat.h>

typedef struct s_routine
{
	unsigned long int	start;
	unsigned long int	last_meal;
	int			tim_die;
	int			tim_eat;
	int			tim_slp;
	int			num_eat;
}	t_routine;

typedef struct s_seat
{
	int				id;
	int				die_flag;
	int				stuffed_flag;
	t_routine		routine;
}	t_seat;

typedef struct s_table
{
	unsigned int	num_seats;
	t_seat			*seats;
	pthread_t		waiter;
	pthread_t		grave_digger;
	sem_t			*fork;
	sem_t			*dead;
	sem_t			*msg;
	pid_t			*pid;
}	t_table;

//src/system
void				clean_bonus(t_table *table);

//init
int					init_process_bonus(t_table *table, int argc, char *argv[]);

// threads
void				setup_table_bonus(t_table *table);
void				create_philo_bonus(t_table *table);
void				control_lunch(t_table *table);
void				wait_and_destroy(t_table *table);

//exec
void				*lunch_bonus(t_table *table);
void				msg_bonus(char *msg, t_table *table);
void				has_taken_a_fork_bonus(t_table *table);
void				is_eating_bonus(t_table *table);
void				is_sleeping_bonus(t_table *table);
void				is_thinking_bonus(t_table *table);

//time
unsigned long int	get_time(void);
unsigned long int	get_now(t_seat *philo);

void				print_(t_table *table, int argc);
#endif
