/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 21:02:03 by aboulbaz          #+#    #+#             */
/*   Updated: 2019/10/18 21:02:05 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char *s;

	if (!(s = (unsigned char*)malloc(size * count)))
		return (NULL);
	ft_bzero(s, size * count);
	return ((void*)s);
}
