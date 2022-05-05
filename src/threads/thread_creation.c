/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:25:32 by fagiusep          #+#    #+#             */
/*   Updated: 2022/05/05 18:27:37 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*	CREATE_THREADS
**	-------
**	DESCRIPTION
**	Execute the follow verifications on the main function arguments:
**	The number of arguments are correct.
**	The arguments are numbers.
**	
**	PARAMETERS
**	
**	RETURN VALUES
**	
**	-------
**	OBS
**	pthread_t - variable it is type int. A large int that is going to unique
**				identify a thread.
**	
**	pthred_create	- it is going to initialize the thread.
**	first param		- new thread ID (pthread_t).
**	second param	- data structure of atributies.
**	third parm		- pointer to the function that you want the new thread to
**					execute.
**	fourth parm		- (void *)parameter o the function passed as the third
**					parameter.
*/

pthread_mutex_t	mutex;

static void	*phil_exec(void *seat)
{
	int		x;
	t_seat	*philo;

	philo = (t_seat *)seat;
//	start_routine(philo);
	x = -1;
	while (++x < 2)
	{
		pthread_mutex_lock(philo->fork_left);
		pthread_mutex_lock(philo->fork_right);

		printf("timestamp %d has taken a fork\n", philo->id);
		printf("timestamp %d is eating\n", philo->id);
		usleep(philo->routine.tim_eat * 1000);

		pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(philo->fork_right);
		printf("timestamp %d finish eating\n", philo->id);
	}
	return ((void *)0);
}

void	thread_creation(t_table *table)
{
	int	i;
	
	pthread_mutex_init(&mutex, NULL);
	i = -1;
	while (++i < table->num_seats)
	{
		if (pthread_create(&table->seats[i].philo, NULL, phil_exec,
			(void*)&table->seats[i]) != 0)
			return ;
		printf("thread  id:%d started!\n", i + 1);
	}
	i = -1;
	while (++i < table->num_seats)
	{
		if (pthread_join(table->seats[i].philo, NULL) != 0)
			return ;
		printf("thread  id:%d finished!\n", i + 1);
	}
	pthread_mutex_destroy(&mutex);
	while (++i < table->num_seats)
		pthread_mutex_destroy(&table->forks[i]);

}