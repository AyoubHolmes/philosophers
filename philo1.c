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

void s_philo1_printer(t_philo1 *philo1)
{
	printf("nbr of philos: %d\n", philo1->nbr_philos);
	printf("time to die: %d\n", philo1->time_to_die);
	printf("time to eat: %d\n", philo1->time_to_eat);
	printf("time to sleep: %d\n", philo1->time_to_sleep);
	if (philo1->nbr_of_meals != -1)
		printf("nbr of meals: %d\n", philo1->nbr_of_meals);
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

void	ft_parsing(t_philo1 *philo1, int argc, char const *argv[])
{
	int	p;

	p = 1;
	printf("\033[0;32mall argument are ready to be parsed.\033[0m\n");
	philo1->nbr_philos = get_postive_int(argv[1], 1, &p);
	philo1->time_to_die = get_postive_int(argv[2], 2, &p);
	philo1->time_to_eat = get_postive_int(argv[3], 3, &p);
	philo1->time_to_sleep = get_postive_int(argv[4], 4, &p);
	philo1->nbr_of_meals = -1;
	if (argc == 6)
		philo1->nbr_of_meals = get_postive_int(argv[5], 5, &p);
	if (p)
		s_philo1_printer(philo1);
	// 😎 controller starts here 😎	
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
