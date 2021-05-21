/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 17:10:10 by aboulbaz          #+#    #+#             */
/*   Updated: 2019/10/31 17:10:17 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		size_int(int n)
{
	int i;
	int temp;

	temp = n;
	i = 0;
	while (temp != 0)
	{
		temp /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int nb)
{
	int		i;
	char	*nbr;

	i = size_int(nb);
	if (nb <= 0)
	{
		if (!(nbr = (char*)malloc(2 + i++)))
			return (0);
		nbr[0] = (nb == 0) ? '0' : '-';
		if (nb == -2147483648)
			return (ft_strdup("-2147483648"));
		else
			nb = nb * -1;
	}
	else if (!(nbr = (char*)malloc(i + 1)))
		return (0);
	nbr[i] = 0;
	while (nb != 0)
	{
		i--;
		nbr[i] = 48 + (nb % 10);
		nb = nb / 10;
	}
	return (nbr);
}
