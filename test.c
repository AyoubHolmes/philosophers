#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <semaphore.h>

char				*ft_itoa(int nb);

void	*ft_thread(void *arg)
{
	sem_t    *test;
	int i;

	test = sem_open(ft_itoa(*(int *)arg), O_CREAT, 0600, 1);
	if (test == SEM_FAILED)
		puts("huge");
	puts("here");
	if((i = sem_wait(test)) < 0)
		puts("error");
	printf("Test in from thread %d\n", *(int *)arg);
	printf("Test out from thread %d\n", *(int *)arg);
	sem_post(test);
	sem_unlink(ft_itoa(*(int *)arg));
	return (NULL);
}

int main(int argc, char const *argv[])
{
	pthread_t p_test[4];
	int			i;
	int			a[4];

	i = 0;
	while (i < 4)
	{
		a[i] = i;
		pthread_create(&p_test[i], NULL, ft_thread, &a[i]);
		sleep(2);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		pthread_join(p_test[i], NULL);
		i++;
	}
	sem_unlink("semaphore_1");
	return 0;
}