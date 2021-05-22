#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>

typedef struct	s_philo1
{
	int			nbr_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nbr_of_meals;
}				t_philo1;
int				ft_isdigit(int c);
int				ft_atoi(const char *str);

#endif
