#include "philosophers.h"

void	philo_lifecycle(t_philos *s)
{
	struct timeval	tp;

	sem_wait(s->forks);
	philo_printer("has taken a fork\n", s, 0);
	sem_wait(s->forks);
	philo_printer("has taken a fork\n", s, 0);
	s->time_counter = ft_timer(0) + s->parse->time_to_die;
	sem_wait(s->life);
	philo_printer("is eating\n", s, s->parse->time_to_eat);
	if (s->nbr_of_meals >= 0)
		s->nbr_of_meals--;
	sem_post(s->life);
	sem_post(s->forks);
	sem_post(s->forks);
	philo_printer("is sleeping\n", s, s->parse->time_to_sleep);
	philo_printer("is thinking\n", s, 0);
}

void	*ft_death_philo(void *s)
{
	t_philos *p;

	p = (t_philos *)s;
	while (p->parse->alive)
	{
		usleep(300);
		sem_wait(p->life);
		if (ft_timer(0) > p->time_counter)
		{
			sem_wait(p->parse->msg);
			if (p->parse->alive == 1)
			{
				if (p->nbr_of_meals == -2)
					printf("%ld\t%d died\n",ft_timer(p->init), p->s);
				else
					printf("\033[0;32mDONE\033[0m\n");
				p->parse->alive = 0;
				sem_post(p->parse->prog);
				return (NULL);
			}
			sem_post(p->parse->msg);
		}
		sem_post(p->life);
	}
	return (NULL);
}

void	ft_philosopher(void *s)
{
	pthread_t		soul_reaper;
	t_philos		*p;
	struct timeval	tp;

	p = (t_philos *)s;
	p->time_counter = ft_timer(0) + (long) p->parse->time_to_die;
	sem_unlink("/life");
	p->life = sem_open("/life",  O_CREAT, 0600, 1);
	pthread_create(&soul_reaper, NULL, ft_death_philo, p);
	if (p->nbr_of_meals == -2)
	{
		while (p->parse->alive)
			philo_lifecycle(p);
	}
	while (p->nbr_of_meals > 0)
		philo_lifecycle(p);
	pthread_join(soul_reaper, NULL);
	exit(0);
}

void	ft_end(pid_t *process_ids, t_philo_parse *philos)
{
	int	i;

	i = 0;
	while (i < philos->nbr_philos)
	{
		kill(process_ids[i], SIGQUIT);
		i++;
	}
}

void	ft_controller(t_philo_parse *philos)
{
	sem_t				*forks;
	
	t_philos			ph;
	pid_t				*process_ids;
	int					i;
	pid_t				pid;

	process_ids = (pid_t *)malloc(sizeof(pid_t));
	i = 0;
	sem_unlink("/forks");
	sem_unlink("/prog");

	printf("****** {THE SIMULATION IS ON} ******\n");
	forks = sem_open("/forks", O_CREAT, 0600, philos->nbr_philos);
	philos->prog = sem_open("/prog", O_CREAT, 0600, 0);
	i = 0;
	while (i < philos->nbr_philos)
	{
		if ((process_ids[i] = fork()) == 0)
			ft_philosopher(get_philo(i + 1, forks, philos));
		usleep(100);
		i++;
	}
	sem_wait(philos->prog);
	sem_post(philos->prog);
	ft_end(process_ids, philos);
}
