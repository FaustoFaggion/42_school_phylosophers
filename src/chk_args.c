/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 09:05:04 by fagiusep          #+#    #+#             */
/*   Updated: 2022/05/01 22:07:27 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	CHK_ARGS
**	-------
**	DESCRIPTION
**	Create a new thread usinf the pthread library functions.
**	PARAMETERS
**	Main function's parameters argc and argv.
**	RETURN VALUES
**	Return 0 for OK and 1 for NOT OK.
**	-------
**	OBS
**	- 
*/

#include "philosophers.h"

int		chk_args(int argc, char *argv[])
{
//	int		index;

	if (argc != 5 && argc != 6)
	{
		printf("argv %s", argv[1]);
		printf("Wrong number of arguments\n");
		return (1);
	}
/*	index = -1;
	while (++index < argc)
	{
		if (ft_isdigit(argv[index]) = 0)
			return (1);
	}
	(*rules).tim_die = ft_atoi(argv[++index]);
	(*rules).tim_eat = ft_atoi(argv[++index]);
	(*rules).tim_slp = ft_atoi(argv[++index]);
	if (argc == 6)
		(*rules).num_eat = ft_atoi(argv[++index]);
*/	return (0);
}