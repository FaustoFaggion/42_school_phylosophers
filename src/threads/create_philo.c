/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:57:56 by fagiusep          #+#    #+#             */
/*   Updated: 2022/05/12 12:26:51 by fausto           ###   ########.fr       */
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

void	create_philo(t_table *table)
{
	int	i;
	int	x;

	i = -1;
	x = -1;
	while (++i < table->num_seats)
	{
		if (pthread_create(&table->seats[i].philo, NULL, lunch,
			(void*)&table->seats[i]) != 0)
			return ;
	}
	while (table->die_flag == 0 && ++x < table->routine.num_eat)
	{
		long int	now;
		
		i = -1;
		usleep((table->routine.tim_die *1000));
		now = get_now(&table->seats[0]);
		printf(" %ld ms death verify!!!!!.....................\n", now);
		while (++i < table->num_seats)
		{
			if ((now - ((unsigned long int)table->seats[i].routine.last_meal)) > (unsigned long int)table->routine.tim_die)
			{
				table->die_flag = 1;
				printf("if: %ldms now: %ldms %d died from Waiter\n", now - ((unsigned long int)table->seats[i].routine.last_meal), now, table->seats[i].id);
				break ;
			}
		}
	}
	i = -1;
	while (++i < table->num_seats)
	{
		if (pthread_join(table->seats[i].philo, NULL) != 0)
			return ;
	}
	i = -1;
	while (++i < table->num_seats)
		pthread_mutex_destroy(&table->forks[i]);
	free(table->forks);
	free(table->seats);
}