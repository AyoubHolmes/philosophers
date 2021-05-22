/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:58:31 by aboulbaz          #+#    #+#             */
/*   Updated: 2019/11/06 16:56:55 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	signe(char c, int *i, int *t)
{
	int k;

	k = *i;
	if (c == '-' || c == '+')
	{
		if (c == '-')
			*t *= -1;
		k++;
		*i = k;
	}
}

int			ft_atoi(const char *str)
{
	int				i;
	int				t;
	unsigned int	s;

	i = 0;
	s = 0;
	t = 1;
	while (ft_isspace(str[i]))
	{
		i++;
	}
	signe(str[i], &i, &t);
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		if (s > 2147483647 && t == -1)
			return (0);
		else if (s > 2147483648 && t == 1)
			return (-1);
		else
		{
			s = s * 10 + str[i] - 48;
			i++;
		}
	}
	return (s * t);
}
