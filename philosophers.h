#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>


typedef struct	s_philo_parse
{
	int				nbr_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_of_meals;
	long			init;
	pthread_mutex_t	*msg;
}				t_philo_parse;

t_philo_parse		parse;
pthread_mutex_t		msg;
pthread_mutex_t *g_m;
pthread_mutex_t *g_p;

typedef struct			s_philos
{
	int				    s;
	pthread_mutex_t		*forks;
	pthread_mutex_t		life;
    struct timeval      tp;
	long				init;
	long				after_eating;
}						t_philos;


int				ft_isdigit(int c);
int				ft_atoi(const char *str);
int 			ft_controller(t_philo_parse *philos);
long			ft_timer(long init);

#endif
