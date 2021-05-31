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
	if (parse->nbr_of_meals != -1)
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

void	ft_parsing(t_philo_parse *parse, int argc, char const *argv[], pthread_mutex_t *g_m)
{
	int	p;
	pthread_mutex_t *msg;

	p = 1;
	printf("\033[0;32mall argument are ready to be parsed.\033[0m\n");
	parse->nbr_philos = get_postive_int(argv[1], 1, &p);
	parse->time_to_die = get_postive_int(argv[2], 2, &p);
	parse->time_to_eat = get_postive_int(argv[3], 3, &p);
	parse->time_to_sleep = get_postive_int(argv[4], 4, &p);
	parse->nbr_of_meals = -2;
	if (argc == 6)
		parse->nbr_of_meals = get_postive_int(argv[5], 5, &p);
	if (p)
	{
		msg = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(msg, NULL);
		s_philo1_printer(parse);
		parse->g_m = g_m;
		parse->msg = msg;
		ft_controller(parse);
	}
}

long	ft_timer(long init)
{
	struct timeval	tp;

	gettimeofday(&tp, NULL);	
	return(((tp.tv_usec / 1000) + (tp.tv_sec * 1000)) - init);
}

int main(int argc, char const *argv[])
{
	int				i;
	struct timeval	tp;
	long			stamp;
	t_philo_parse	parse;
	pthread_mutex_t g_m;

	gettimeofday(&tp, NULL);
	parse.init = ((tp.tv_usec / 1000) + (tp.tv_sec * 1000));
	printf("****** TIMER: %ld ***********\n\n", parse.init);
	pthread_mutex_init(&g_m, NULL);
	pthread_mutex_lock(&g_m);
	if (argc == 5 || argc == 6)
	{
		i = 0;
		while (++i < argc)
			if (!is_a_number(argv[i]))
			{
				printf("\033[1;31mthe argument %d is not a number!\033[0m\n", i);
				pthread_mutex_unlock(&g_m);
				return (1);
			}
		if (i == argc)
			ft_parsing(&parse, argc, argv, &g_m);
	} 
	else
	{
		printf("\033[1;31mnumber of parameters is wrong!\033[0m\n");
		pthread_mutex_unlock(&g_m);
		return (1);
	}
	pthread_mutex_lock(&g_m);
	return (0);
} 
 