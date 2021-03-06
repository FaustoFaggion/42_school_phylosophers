/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 06:56:30 by fagiusep          #+#    #+#             */
/*   Updated: 2022/05/13 12:47:00 by fausto           ###   ########.fr       */
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
	if (table->forks != NULL)
		free(table->forks);
	if (table->seats != NULL)
		free(table->seats);
}
