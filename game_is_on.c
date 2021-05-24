#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct			s_philos
{
	int				    s;
	pthread_mutex_t		*lock;
    struct timeval      tp;
    int		            boolean;
}						t_philos;

t_philos	*get_philo(int str, pthread_mutex_t *lock)
{
	t_philos *ph;

	ph = (t_philos *)malloc(sizeof(t_philos));
	ph->s = str;
	ph->lock = lock;
	return (ph);
}


void *myThreadFun(void *s)
{
	pthread_mutex_lock(((t_philos *)s)->lock);
	printf("\n\n********************************\n");
	printf("Printing from Thread: %d\n", ((t_philos *)s)->s);
	((t_philos *)s)->boolean = gettimeofday(&((t_philos *)s)->tp, NULL);
	printf("Boolean: %d\n", !((t_philos *)s)->boolean);
	printf("Time per seconds: %ld\n", ((t_philos *)s)->tp.tv_sec);
	printf("Time per microseconds: %d\n", ((t_philos *)s)->tp.tv_usec);
	printf("\n********************************\n");
	pthread_mutex_unlock(((t_philos *)s)->lock);
	return NULL;
}

int main(int argc, char const *argv[])
{
    pthread_mutex_t		lock;
	t_philos			ph;
    pthread_t			thread_ids[5];
    int                 i;

    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("\n mutex init has failed\n");
        return 1;
    }
    if (argc == 1)
        return 1;
    // thread_ids = (pthread_t *)malloc(sizeof(pthread_t) * atoi(argv[1]));
    printf("num :%d\n", atoi(argv[1]));
    printf("************************** THE GAME IS ON! **************************\n");
    i = 0;
    while (i < 5)
    {
        pthread_create(&thread_ids[i], NULL, myThreadFun, get_philo(i, &lock));
        i++;
    }
    i = 0;
    while (i < 5)
    {
        pthread_detach(thread_ids[i]);
        i++;
    }
    pthread_mutex_destroy(&lock);
    return 0;
}
