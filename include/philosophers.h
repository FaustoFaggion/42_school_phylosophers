#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>

# include "../libft/libft.h"


typedef struct s_rules
{
	int	phi_num;
	int	tim_die;
	int	tim_eat;
	int	tim_slp;
	int	num_eat;
}	t_rules;


int		main(int argc, char *argv[]);

//src/system

int	chk_args_(t_rules *rules, int argc, char *argv[]);

#endif