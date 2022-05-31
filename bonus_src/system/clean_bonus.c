/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 06:56:30 by fagiusep          #+#    #+#             */
/*   Updated: 2022/05/31 15:44:15 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

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

void	clean_bonus(t_table *table)
{
	if (table->seats != NULL)
		free(table->seats);
	if (table->pid != NULL)
		free(table->pid);
}
