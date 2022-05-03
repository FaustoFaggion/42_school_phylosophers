#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_routine	routine;

	if (init_process(&routine, argc, argv) == 1)
		return (1);
	thread_creation();
//	pthread_exit;
	return (0);
}
