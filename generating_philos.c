#include "philosophers.h"

t_philos	*get_philo(int id, long init, pthread_mutex_t *forks)
{
	t_philos *ph;

	ph = (t_philos *)malloc(sizeof(t_philos));
	pthread_mutex_init(&ph->life, NULL);
	ph->s = id;
	ph->forks = forks;
	ph->init = init;
	return (ph);
}



void	philo_printer(char *s, long arg1, int arg2, int sleep)
{

	pthread_mutex_lock(&msg);
	printf("%ld\t%d %s", arg1, arg2, s);
	pthread_mutex_unlock(&msg);
	usleep(sleep * 1000);
}

void	philo_lifecycle(t_philos *s)
{
	pthread_mutex_lock(&(s)->forks[(s)->s - 1]);
	philo_printer("has taken a fork\n", ft_timer(s->init), (s)->s, 0);
	pthread_mutex_lock(&(s)->forks[((s)->s) % parse.nbr_philos]);
	philo_printer("has taken a fork\n", ft_timer(s->init), (s)->s, 0);

	pthread_mutex_lock(&s->life);
	s->after_eating = ft_timer(0) + parse.time_to_die;
	philo_printer("is eating\n", ft_timer(s->init), (s)->s, parse.time_to_eat);
	pthread_mutex_unlock(&s->life);

	pthread_mutex_unlock(&(s)->forks[(s)->s - 1]);
	pthread_mutex_unlock(&(s)->forks[((s)->s) % parse.nbr_philos]); 

	philo_printer("is sleeping\n", ft_timer(s->init), (s)->s, parse.time_to_sleep);
	philo_printer("is thinking\n", ft_timer(s->init), (s)->s, 0);
	// if (ft_timer(((t_philos *)s)->after_eating) > parse.time_to_die)
	// {
	// 	pthread_mutex_lock(&msg);
	// 	printf("%ld\t%d died\n",ft_timer(((t_philos *)s)->init), ((t_philos *)s)->s);
	// 	pthread_mutex_unlock(&g_m);
	// }
}

void	*ft_death_philo(void *s)
{
	t_philos *p;

	p = (t_philos *)s;
	while (1)
	{
		pthread_mutex_lock(&p->life);
		if (ft_timer(0) > p->after_eating)
		{
			pthrea d_mutex_lock(&msg);
			printf("%ld\t%d died\n",ft_timer(p->init), p->s);
			// pthread_mutex_unlock(&p->life);
			pthread_mutex_unlock(g_m);
			return (NULL);
		}
		pthread_mutex_unlock(&p->life);
		usleep(100);
	}
	return (NULL);
}

void	*ft_philosopher(void *s)
{
	pthread_t		soul_reaper;
	t_philos		*p;

	p = (t_philos *)s;
	p->after_eating = ft_timer(0) + parse.time_to_die;
	pthread_create(&soul_reaper, NULL, ft_death_philo, p);
	pthread_detach(soul_reaper);
	while (1)
		philo_lifecycle(p);
	return (NULL);
}

int	ft_controller(t_philo_parse *philos)
{
	pthread_mutex_t		*forks;
	t_philos			ph;
	pthread_t			thread_id;
	int					i;

	forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * philos->nbr_philos);
	g_p = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(g_p, NULL);
	pthread_mutex_init(&msg, NULL);

	i = 0;
	while (i < philos->nbr_philos)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0) {
			printf("\n mutex init has failed\n");
			return (1);
		}
		i++;
	}
	printf("****** {THE SIMULATION IS ON: %d} ******\n", parse.nbr_philos);
	i = 0;
	while (i < philos->nbr_philos)
	{
		pthread_create(&thread_id, NULL, ft_philosopher, get_philo(i + 1, philos->init, forks));
		pthread_detach(thread_id);
		usleep(100);
		i++;
	}
	i = 0;
	while (i < philos->nbr_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	return (0);
}
