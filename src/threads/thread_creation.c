/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:25:32 by fagiusep          #+#    #+#             */
/*   Updated: 2022/05/04 10:09:19 by fagiusep         ###   ########.fr       */
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

long	value;
pthread_mutex_t	mutex;

static void	*phil_exec()
{
	int	i;

	i = 0;
	pthread_mutex_lock(&mutex);
	while(++i < 1000000)
		value++;
	pthread_mutex_unlock(&mutex);
	return ((void *)0);
}

void	thread_creation(pthread_t *philo)
{	
	pthread_mutex_init(&mutex, NULL);
	value = 0;
	pthread_create(philo, NULL, phil_exec, NULL);
	pthread_join(*philo, NULL); //code valt first video
	printf("value: %ld\n", value);
	pthread_mutex_destroy(&mutex);
}