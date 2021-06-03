#include "philosophers.h"

int	is_a_number(const char *s)
{
	if (s)
	{
		if (*s == '-')
			s++;
		while(*s)
		{
			if (!ft_isdigit(*s))
				return (0);
			s++;
		}
	}
	return (1);
}

void s_philo1_printer(t_philo_parse *parse)
{
	printf("nbr of philos: %d\n", parse->nbr_philos);
	printf("time to die: %d\n", parse->time_to_die);
	printf("time to eat: %d\n", parse->time_to_eat);
	printf("time to sleep: %d\n", parse->time_to_sleep);
	if (parse->nbr_of_meals != -2)
		printf("nbr of meals: %d\n", parse->nbr_of_meals);
}

int		get_postive_int(const char *s, int i, int *p)
{
	int	nbr;

	nbr = -1;
	if (*p == 1)
	{
		nbr = ft_atoi(s);
		if (nbr < 0)
		{
			printf("\033[1;31mthe argument %d is a negative value!\033[0m\n", i);
			*p = 0;
			return (-1);
		}
	}
	return (nbr);
}


t_philos	*get_philo(int id, sem_t *forks, t_philo_parse *parse)
{
	t_philos *ph;

	ph = (t_philos *)malloc(sizeof(t_philos));
	ph->s = id;
	ph->forks = forks;
	ph->init = parse->init;
	ph->nbr_of_meals = parse->nbr_of_meals;
	ph->parse = parse;
	return (ph);
}

void	philo_printer(char *s, t_philos *p, int sleep)
{
	if (p->parse->alive && (p->nbr_of_meals > 0 || p->nbr_of_meals == -2))
	{
		sem_wait(p->parse->msg);
		printf("%ld\t%d %s", ft_timer(p->init), p->s, s);
		sem_post(p->parse->msg);
		usleep(sleep * 1000);
	}
}
