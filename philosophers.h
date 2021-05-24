#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>


typedef struct	s_philo1
{
	int			nbr_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nbr_of_meals;
}				t_philo1;
int				ft_isdigit(int c);
int				ft_atoi(const char *str);

/*

**	usleep: sleep per microseconds
**  gettimeofday:  /  struct timeval tp; / tp.tv_sec: seconds since Jan. 1, 1970  / tp.tv_usec: and microseconds
**  pthread_create
**  pthread_detach
**  pthread_mutex_init
**  pthread_mutex_lock
**  pthread_mutex_unlock
**  pthread_mutex_destroy

*/

#endif
