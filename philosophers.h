#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>


typedef struct		s_philo_parse
{
	int				nbr_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_of_meals;
	long			init;
	pthread_mutex_t	*msg;
	pthread_mutex_t *g_m;
}					t_philo_parse;

typedef struct			s_philos
{
	t_philo_parse		*parse;
	int				    s;
	pthread_mutex_t		*forks;
	pthread_mutex_t		life;
    struct timeval      tp;
	long				init;
	long				time_counter;
	struct timeval		t_limit;
	int					nbr_of_meals;
}						t_philos;


int				ft_isdigit(int c);
int				ft_atoi(const char *str);
int 			ft_controller(t_philo_parse *philos);
long			ft_timer(long init);

#endif
