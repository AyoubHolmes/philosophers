#include "philosophers.h"

t_philos	*get_philo(int str, pthread_mutex_t *lock, long init, pthread_mutex_t *forks)
{
	t_philos *ph;

	ph = (t_philos *)malloc(sizeof(t_philos));
	ph->s = str;
	ph->lock = lock;
	ph->forks = forks;
	ph->init = init;
	return (ph);
}

/* void	*ft_philosopher(void *s)
{
	pthread_mutex_lock(((t_philos *)s)->lock);
	printf("\n\n********************************\n");
	printf("Printing from Philosopher: %d\n", ((t_philos *)s)->s);
	printf("Timer per miliseconds: %ld\n", ft_timer(((t_philos *)s)->init));
	printf("********************************\n");
	pthread_mutex_unlock(((t_philos *)s)->lock);
	return NULL;
} */

void	*ft_philosopher(void *s)
{
	pthread_mutex_lock(&((t_philos *)s)->forks[((t_philos *)s)->s]);
	pthread_mutex_lock(&((t_philos *)s)->forks[(((t_philos *)s)->s + 1) % philo1.nbr_philos]);
	printf("philosopher %d is eating\n", ((t_philos *)s)->s);
	pthread_mutex_unlock(&((t_philos *)s)->forks[(((t_philos *)s)->s + 1) % philo1.nbr_philos]);
	pthread_mutex_unlock(&((t_philos *)s)->forks[((t_philos *)s)->s]);
	return NULL;
}

int	ft_controller(t_philo1 *philos)
{
	pthread_mutex_t		lock;
	pthread_mutex_t		*forks;
	t_philos			ph;
	pthread_t			*thread_ids;
	int					i;

	forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * philos->nbr_philos);
	if (pthread_mutex_init(&lock, NULL) != 0) {
		printf("\n mutex init has failed\n");
		return (1);
	}
	// -----------------------
	i = 0;
	while (i < philos->nbr_philos)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0) {
			printf("\n mutex init has failed\n");
			return (1);
		}
		i++;
	}
	// -----------------------
	thread_ids = (pthread_t *)malloc(sizeof(pthread_t) * philos->nbr_philos);
	printf("***************** {THE SIMULATION IS ON} *****************\n");
	i = 0;
	while (i < philos->nbr_philos)
	{
		pthread_create(&thread_ids[i], NULL, ft_philosopher, get_philo(i + 1, &lock, philos->init, forks));
		pthread_detach(thread_ids[i]);
		i++;
	}
	// -----------------------
	i = 0;
	while (i < philos->nbr_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	// -----------------------
	pthread_mutex_destroy(&lock);
	free(thread_ids);
	return (0);
}
