#include "philosophers.h"

t_philos	*get_philo(int id, long init, pthread_mutex_t *forks)
{
	t_philos *ph;

	ph = (t_philos *)malloc(sizeof(t_philos));
	ph->s = id;
	ph->forks = forks;
	ph->init = init;
	return (ph);
}

void	eat(t_philos *s)
{
	pthread_mutex_lock(&(s)->forks[(s)->s]);
	printf("%ld\t%d has taken a fork\n", ft_timer(s->init), (s)->s);
	pthread_mutex_lock(&(s)->forks[((s)->s + 1) % philo1.nbr_philos]);
	printf("%ld\t%d has taken a fork\n", ft_timer(s->init),(s)->s);
	printf("%ld\t%d is eating\n",ft_timer(s->init), (s)->s);
	usleep(philo1.time_to_eat * 1000);
	pthread_mutex_unlock(&(s)->forks[((s)->s + 1) % philo1.nbr_philos]);
	pthread_mutex_unlock(&(s)->forks[(s)->s]);
	printf("%ld\t%d is sleeping\n",ft_timer(s->init), (s)->s);
	usleep(philo1.time_to_sleep * 1000);
	printf("%ld\t%d is thinking\n",ft_timer(s->init), (s)->s);
	// if (die)
	// 	pthread_mutex_unlock(&g_m); 
	// protect printf with mutex
}

void	*ft_philosopher(void *s)
{
	while (1)
		eat((t_philos *)s);
	return NULL;
}

int	ft_controller(t_philo1 *philos)
{
	pthread_mutex_t		*forks;
	t_philos			ph;
	pthread_t			*thread_ids;
	int					i;

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
	thread_ids = (pthread_t *)malloc(sizeof(pthread_t) * philos->nbr_philos);
	printf("***************** {THE SIMULATION IS ON: %d} *****************\n", philo1.nbr_philos);
	i = 0;
	while (i < philos->nbr_philos)
	{
		pthread_create(&thread_ids[i], NULL, ft_philosopher, get_philo(i + 1, philos->init, forks));
		pthread_detach(thread_ids[i]);
		i++;
	}
	i = 0;
	while (i < philos->nbr_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	free(thread_ids);
	return (0);
}
