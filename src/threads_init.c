/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 16:13:47 by fagiusep          #+#    #+#             */
/*   Updated: 2022/04/30 18:54:36 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	threads_init(t_data *data, int num_phil)
{
	int	i;
	
	i = 0;
	data->phil = (long *)ft_calloc(num_phil + 1, sizeof(pthread_t));
	while (i < num_phil)
	{
		data->phil[i] = thread_creation();
		i++;;
	}
	return (0);
}