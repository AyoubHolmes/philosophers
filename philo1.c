#include "philosophers.h"

int	is_a_number(const char *s)
{
	if (s)
	{
		while(*s)
		{
			if (!ft_isdigit(*s))
				return (0);
			s++;
		}
	}
	return (1);
}

void s_philo1_printer(t_philo1 *philo1)
{
	printf("nbr of philos: %d\n", philo1->nbr_philos);
	printf("time to die: %d\n", philo1->time_to_die);
	printf("time to eat: %d\n", philo1->time_to_eat);
	printf("time to sleep: %d\n", philo1->time_to_sleep);
	printf("nbr of meals: %d\n", philo1->nbr_of_meals);
}

void	ft_parsing(t_philo1 *philo1, int argc, char const *argv[])
{
	printf("all argument are ready to be parsed.\n");
	philo1->nbr_philos = ft_atoi(argv[1]);
	philo1->time_to_die = ft_atoi(argv[2]);
	philo1->time_to_eat = ft_atoi(argv[3]);
	philo1->time_to_sleep = ft_atoi(argv[4]);
	philo1->nbr_of_meals = -1;
	if (argc == 6)
		philo1->nbr_of_meals = ft_atoi(argv[5]);
	s_philo1_printer(philo1);
	// 😎 controller starts 😎
	
}

int main(int argc, char const *argv[])
{
	int i;
	t_philo1 philo1;

	if (argc == 5 || argc == 6)
	{
		i = 1;
		while (i < argc)
		{
			if (!is_a_number(argv[i]))
			{
				printf("\033[1;31mthe argument %d is not a number!\033[0m\n", i);
				break ;
			}
			i++;
		}
		if (i == argc)
			ft_parsing(&philo1, argc, argv);
	} 
	else
		printf("\033[1;31mnumber of parameters is wrong!\033[0m\n");
	return 0;
}
