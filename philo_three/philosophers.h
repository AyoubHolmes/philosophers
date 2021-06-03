#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <semaphore.h>
#include <signal.h>


typedef struct		s_philo_parse
{
	int				nbr_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_of_meals;
	long			init;
	int				alive;
	sem_t			*msg;
	sem_t			*prog;
}					t_philo_parse;

typedef struct			s_philos
{
	t_philo_parse		*parse;
	int				    s;
	sem_t		*forks;
	sem_t		*life;
    struct timeval      tp;
	long				init;
	long				time_counter;
	struct timeval		t_limit;
	int					nbr_of_meals;
}						t_philos;

int				ft_isdigit(int c);
int				ft_atoi(const char *str);
void 			ft_controller(t_philo_parse *philos);
long			ft_timer(long init);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
int				is_a_number(const char *s);
void			s_philo1_printer(t_philo_parse *parse);
int				get_postive_int(const char *s, int i, int *p);
t_philos		*get_philo(int id, sem_t *forks, t_philo_parse *parse);
void			philo_printer(char *s, t_philos *p, int sleep);


#endif
