/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:25:32 by fagiusep          #+#    #+#             */
/*   Updated: 2022/05/08 12:01:44 by fagiusep         ###   ########.fr       */
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

static void	start_table(t_table *table)
{
	int	i;

	table->routine.start = get_time();
	i = -1;
	while (++i < table->num_seats)
		table->seats->routine.start = table->routine.start;
}

void	thread_creation(t_table *table)
{
	int	i;
	
	start_table(table);
	i = -1;
	while (++i < table->num_seats)
	{
		if (pthread_create(&table->seats[i].philo, NULL, exec_philo,
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
	while (++i < table->num_seats)
		pthread_mutex_destroy(&table->forks[i]);

}