/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:25:32 by fagiusep          #+#    #+#             */
/*   Updated: 2022/05/05 14:52:22 by fagiusep         ###   ########.fr       */
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

static void	*phil_exec(void *value)
{
//	int	i;
	int	x;
	t_seat	*temp;

	temp = (t_seat *)value;
	
	x = -1;
	while (++x < 2)
	{
		pthread_mutex_lock(&mutex);
		printf("id: %d\n", temp->id);
//		i = 0;
//		while (++i <= 100)
//			(*(int *)value)++;
		pthread_mutex_unlock(&mutex);
	}
	return ((void *)value);
}

void	thread_creation(t_table *table)
{
	int	i;
//	int	*value;
	
//	value = ft_calloc(1, sizeof(int));
//	*value = 0;
	srand(time(NULL));
	pthread_mutex_init(&mutex, NULL);
	i = -1;
	while (++i < table->num_seats)
	{
		if (pthread_create(&table->seats[i].philo, NULL, phil_exec,
			(void*)&table->seats[i]) != 0)
			return ;
		printf("thread  id:%d started!\n", i);
	}
	i = -1;
	while (++i < table->num_seats)
	{
		if (pthread_join(table->seats[i].philo, NULL) != 0)
			return ;
		printf("thread  id:%d finished!\n", i);
	}
//	printf("value: %d\n", *value);
	pthread_mutex_destroy(&mutex);
//	free(value);
}