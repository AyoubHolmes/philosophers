/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:02:12 by aboulbaz          #+#    #+#             */
/*   Updated: 2019/10/23 15:02:15 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*p;

	i = 0;
	if (!s)
	{
		return (NULL);
	}
	if (!f)
	{
		return (NULL);
	}
	if (!(p = ft_strdup(s)))
		return (NULL);
	while (p[i] != '\0')
	{
		p[i] = f(i, p[i]);
		i++;
	}
	return (p);
}
