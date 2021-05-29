#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

void    *ft_philosopher()
{
    pthread_mutex_t g_m;
    pthread_mutexattr_t Attr;

    pthread_mutexattr_init(&Attr);
    pthread_mutexattr_settype(&Attr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&g_m, &Attr);
    pthread_mutex_lock(&g_m);
    pthread_mutex_lock(&g_m);
    printf("here\n");
    pthread_mutex_unlock(&g_m);
    pthread_mutex_lock(&g_m);
    printf("here2\n");
    pthread_mutex_unlock(&g_m);
    return (NULL);
}
int main(int argc, char const *argv[])
{
    pthread_t       thread_id;

    pthread_create(&thread_id, NULL, ft_philosopher, NULL);
    pthread_detach(thread_id);
    return 0;
}
