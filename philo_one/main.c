#include "philosophers.h"

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
		parse->alive = 1;
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
	t_philo_parse	*parse;
	pthread_mutex_t g_m;
	

	gettimeofday(&tp, NULL);
	parse = (t_philo_parse *)malloc(sizeof(t_philo_parse));
	parse->init = ((tp.tv_usec / 1000) + (tp.tv_sec * 1000));
	if (argc == 5 || argc == 6)
	{
		i = 0;
		while (++i < argc)
			if (!is_a_number(argv[i]))
			{
				printf("\033[1;31mthe argument %d is not a number!\033[0m\n", i);
				free(parse);
				return (1);
			}
		if (i == argc)
			ft_parsing(parse, argc, argv, &g_m);
	} 
	else
	{
		printf("\033[1;31mnumber of parameters is wrong!\033[0m\n");
		free(parse);
		return (1);
	}
	return (0);
} 
 