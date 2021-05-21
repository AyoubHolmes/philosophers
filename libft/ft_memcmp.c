/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 18:30:10 by aboulbaz          #+#    #+#             */
/*   Updated: 2019/10/30 18:30:11 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *st;
	unsigned char *sr;

	st = (unsigned char *)s1;
	sr = (unsigned char *)s2;
	while (n--)
	{
		if (*st != *sr)
			return (*st - *sr);
		st++;
		sr++;
	}
	return (0);
}
