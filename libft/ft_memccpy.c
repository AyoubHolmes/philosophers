/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:40:00 by aboulbaz          #+#    #+#             */
/*   Updated: 2019/10/18 13:40:05 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *str1, const void *str2, int c, size_t n)
{
	size_t				i;
	unsigned const char *src;
	unsigned char		*dst;

	src = (unsigned const char *)str2;
	dst = (unsigned char *)str1;
	if (!str1 && !str2)
		return (0);
	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		if (dst[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (0);
}
