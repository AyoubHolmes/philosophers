#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct			s_philos
{
	char				*s;
	pthread_mutex_t		*lock;
}						t_philos;

t_philos	*get_philo(char *str, pthread_mutex_t *lock)
{
	t_philos *ph;

	ph = (t_philos *)malloc(sizeof(t_philos));
	ph->s = str;
	ph->lock = lock;
	return (ph);
}

void *myThreadFun(void *s)
{/* 
	int test;

	test = usleep(10000000); */
	t_philos *str = (t_philos *)s;
	struct timeval tp;
	int		boolean;

	pthread_mutex_lock(((t_philos *)s)->lock);
	printf("\n********************************\n");
	printf("Printing from Thread: %s\n", str->s);
	boolean = gettimeofday(&tp, NULL);
	printf("Boolean: %d\n", !boolean);
	printf("Time per seconds: %ld\n", tp.tv_sec);
	printf("Time per microseconds: %d\n", tp.tv_usec);
	printf("\n********************************\n");
	// printf("%d\n", test);
	pthread_mutex_unlock(str->lock);
	return NULL;
}

int main(int argc, char const *argv[])
{
	pthread_mutex_t		lock;
	t_philos			ph;
	pthread_t			thread_id1;
	pthread_t			thread_id2;
	pthread_t			thread_id3;
	pthread_t			thread_id4;
	pthread_t			thread_id5;

    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("\n mutex init has failed\n");
        return 1;
    }

	printf("************************** Before All Threads **************************\n");
	pthread_create(&thread_id1, NULL, myThreadFun, get_philo("Hello World **** {1} ****", &lock));
	pthread_create(&thread_id2, NULL, myThreadFun, get_philo("Hello World **** {2} ****", &lock));
	pthread_create(&thread_id3, NULL, myThreadFun, get_philo("Hello World **** {3} ****", &lock));
	pthread_create(&thread_id4, NULL, myThreadFun, get_philo("Hello World **** {4} ****", &lock));
	pthread_create(&thread_id5, NULL, myThreadFun, get_philo("Hello World **** {5} ****", &lock));
	pthread_join(thread_id1, NULL);
	pthread_join(thread_id2, NULL);
	pthread_join(thread_id3, NULL);
	pthread_join(thread_id4, NULL);
	pthread_join(thread_id5, NULL);
	pthread_mutex_destroy(&lock);
	return 0;
}
