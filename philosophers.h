#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>


typedef struct	s_philo1
{
	int			nbr_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nbr_of_meals;
}				t_philo1;

typedef struct			s_philos
{
	int				    s;
	pthread_mutex_t		*lock;
    struct timeval      tp;
    int		            boolean;
}						t_philos;

int				ft_isdigit(int c);
int				ft_atoi(const char *str);
int 			ft_controller(t_philo1 *philos);

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
