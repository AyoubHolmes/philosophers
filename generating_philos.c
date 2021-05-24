#include "philosophers.h"

t_philos	*get_philo(int str, pthread_mutex_t *lock)
{
	t_philos *ph;

	ph = (t_philos *)malloc(sizeof(t_philos));
	ph->s = str;
	ph->lock = lock;
	return (ph);
}

void	*ft_philosopher(void *s)
{
	pthread_mutex_lock(((t_philos *)s)->lock);
	printf("\n\n********************************\n");
	printf("Printing from Philosopher: %d\n", ((t_philos *)s)->s);
	((t_philos *)s)->boolean = gettimeofday(&((t_philos *)s)->tp, NULL);
	printf("Boolean: %d\n", !((t_philos *)s)->boolean);
	printf("Time per seconds: %ld\n", ((t_philos *)s)->tp.tv_sec);
	printf("Time per miliseconds: %d\n", ((t_philos *)s)->tp.tv_usec * 1000);
	printf("********************************\n");
	pthread_mutex_unlock(((t_philos *)s)->lock);
	return NULL;
}

int	ft_controller(t_philo1 *philos)
{
	pthread_mutex_t		lock;
	t_philos			ph;
	pthread_t			*thread_ids;
	int					i;

	i = 0;
	if (pthread_mutex_init(&lock, NULL) != 0) {
		printf("\n mutex init has failed\n");
		return (1);
	}
	thread_ids = (pthread_t *)malloc(sizeof(pthread_t) * philos->nbr_philos);
	printf("***************** {THE SIMULATION IS ON} *****************\n");
	while (i < philos->nbr_philos)
	{
		pthread_create(&thread_ids[i], NULL, ft_philosopher, get_philo(i + 1, &lock));
		pthread_detach(thread_ids[i]);
		i++;
	}
	pthread_mutex_destroy(&lock);
	free(thread_ids);
	return (0);
}
