#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

pthread_mutex_t		lock;

void    *function(void *test)
{
    pthread_mutex_lock(&lock);
    int *p = (int *)test;
    (*p)++;
    printf("%d\n", *p);
    printf("%d\n", *p);
    printf("%d\n", *p);
    printf("%d\n", *p);
    pthread_mutex_unlock(&lock);
    return (NULL);
}

int main(int argc, char const *argv[])
{
    pthread_t thread[7];
    
    int i;

    if (pthread_mutex_init(&lock, NULL) != 0) {
		printf("\n mutex init has failed\n");
		return (1);
	}
    i = 0;
    pthread_create(&thread[0], NULL, function, &i);
    pthread_detach(thread[0]);
    pthread_create(&thread[1], NULL, function, &i);
    pthread_detach(thread[1]);
    pthread_create(&thread[2], NULL, function, &i);
    pthread_detach(thread[2]);
    pthread_create(&thread[3], NULL, function, &i);
    pthread_detach(thread[3]);
    pthread_create(&thread[4], NULL, function, &i);
    pthread_detach(thread[4]);
    pthread_create(&thread[5], NULL, function, &i);
    pthread_detach(thread[5]);
    pthread_create(&thread[6], NULL, function, &i);
    pthread_detach(thread[6]);
    pthread_mutex_destroy(&lock);
    return 0;
}
