/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 06:56:30 by fagiusep          #+#    #+#             */
/*   Updated: 2022/05/06 08:04:24 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*	CLEAN
**	-------
**	DESCRIPTION
**	Free all the memory allocated before ending the process
**	-------
**	PARAMETERS
**	1. typedef struct table - This struct cotain all the main parâmeters of the
**	program.
**	RETURN VALUES
**	-
**	-------
*/

void	clean(t_table *table)
{
	sleep(2);
	if (table->seats != NULL)
		free(&table->seats);
	if (table->forks != NULL)
		free(&table->forks);
}