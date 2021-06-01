#include "philosophers.h"

t_philos	*get_philo(int id, pthread_mutex_t *forks, t_philo_parse *parse)
{
	t_philos *ph;

	ph = (t_philos *)malloc(sizeof(t_philos));
	ph->s = id;
	ph->forks = forks;
	ph->init = parse->init;
	ph->nbr_of_meals = parse->nbr_of_meals;
	ph->parse = parse;
	return (ph);
}

void	philo_printer(char *s, t_philos *p, int sleep)
{
	if (p->parse->alive)
	{
		pthread_mutex_lock(p->parse->msg);
		printf("%ld\t%d %s", ft_timer(p->init), p->s, s);
		pthread_mutex_unlock(p->parse->msg);
		usleep(sleep * 1000);
	}
}

void	philo_lifecycle(t_philos *s)
{
	struct timeval	tp;

	pthread_mutex_lock(&s->life);
	pthread_mutex_lock(&(s)->forks[(s)->s - 1]);
	philo_printer("has taken a fork\n", s, 0);
	pthread_mutex_lock(&(s)->forks[((s)->s) % s->parse->nbr_philos]);
	philo_printer("has taken a fork\n", s, 0);
	s->time_counter = ft_timer(0) + s->parse->time_to_die;
	philo_printer("is eating\n", s, s->parse->time_to_eat);
	pthread_mutex_unlock(&(s)->forks[(s)->s - 1]);
	pthread_mutex_unlock(&(s)->forks[((s)->s) % s->parse->nbr_philos]); 
	pthread_mutex_unlock(&s->life);
	philo_printer("is sleeping\n", s, s->parse->time_to_sleep);
	philo_printer("is thinking\n", s, 0);
}

void	*ft_death_philo(void *s)
{
	t_philos *p;

	p = (t_philos *)s;
	while (p->parse->alive)
	{
		usleep(100);
		pthread_mutex_lock(&p->life);
		if (ft_timer(0) > p->time_counter)
		{
			pthread_mutex_lock(p->parse->msg);
			if (p->parse->alive == 1)
			{
				if (p->nbr_of_meals == -2)
					printf("%ld\t%d died\n",ft_timer(p->init), p->s);
				else
					printf("\033[0;32mDONE\033[0m\n");
				p->parse->alive = 0;
			}
			pthread_mutex_unlock(p->parse->msg);
		}
		pthread_mutex_unlock(&p->life);
	}
	return (NULL);
}

void	*ft_philosopher(void *s)
{
	pthread_t		soul_reaper;
	t_philos		*p;
	struct timeval	tp;

	p = (t_philos *)s;
	p->time_counter = ft_timer(0) + (long) p->parse->time_to_die;
	pthread_mutex_init(&p->life, NULL);
	pthread_create(&soul_reaper, NULL, ft_death_philo, p);
	if (p->nbr_of_meals == -2)
	{
		while (p->parse->alive)
			philo_lifecycle(p);
	}
	while (p->nbr_of_meals-- > 0)
		philo_lifecycle(p);
	pthread_join(soul_reaper, NULL);
	return (NULL);
}

int	ft_controller(t_philo_parse *philos)
{
	pthread_mutex_t		*forks;
	t_philos			ph;
	pthread_t			*thread_ids;
	int					i;

	thread_ids = (pthread_t *)malloc(sizeof(pthread_t));
	forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * philos->nbr_philos);
	i = 0;
	while (i < philos->nbr_philos)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0) {
			printf("\n mutex init has failed\n");
			return (1);
		}
		i++;
	}
	printf("****** {THE SIMULATION IS ON} ******\n");
	i = 0;
	while (i < philos->nbr_philos)
	{
		pthread_create(&thread_ids[i], NULL,
			ft_philosopher, get_philo(i + 1, forks, philos));
		usleep(100);
		i++;
	}
	i = 0;
	while (i < philos->nbr_philos)
	{
		pthread_join(thread_ids[i], NULL);
		i++;
	}
	i = 0;
	while (i < philos->nbr_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	free(thread_ids);
	free(forks);
	return (0);
}
