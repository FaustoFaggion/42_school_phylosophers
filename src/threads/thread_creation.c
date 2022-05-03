/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:25:32 by fagiusep          #+#    #+#             */
/*   Updated: 2022/05/03 13:24:56 by fagiusep         ###   ########.fr       */
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

static void	*phil_exec()
{
	printf("phil_exec function!\n");
	sleep(2);
	printf("end phil_exec function!\n");
	return ((void *)0);
}

pthread_t	thread_creation()
{
	pthread_t	p1;
	pthread_t	p2;

	if (pthread_create(&p1, NULL, phil_exec, NULL) != 0)
		return (1);
	if (pthread_create(&p2, NULL, phil_exec, NULL) != 0)
		return (1);
	pthread_join(p1, NULL); //code valt first video
	pthread_join(p2, NULL); //code valt first video
	return(p1);
}