/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:54:14 by aboulbaz          #+#    #+#             */
/*   Updated: 2019/11/02 15:03:04 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	exists(char c, const char *set)
{
	size_t i;

	i = 0;
	if (set)
	{
		while (set[i])
		{
			if (c == set[i++])
				return (1);
		}
	}
	return (0);
}

static size_t	first_str(const char *s, const char *set)
{
	size_t i;

	i = 0;
	if (s && set)
	{
		while (exists(s[i], set))
			i++;
		return (i);
	}
	return (0);
}

static size_t	last_str(const char *s, const char *set, size_t lens)
{
	size_t i;

	i = 0;
	if (s && set && lens > 0)
	{
		while (exists(s[lens - i - 1], set))
			i++;
		return (i);
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int len;
	int start;

	if (!set || !s1)
		return (NULL);
	if (s1[first_str(s1, set)] == '\0')
		return (ft_strdup(""));
	start = first_str(s1, set);
	len = ft_strlen(s1 + start) - last_str(s1, set, ft_strlen(s1));
	return (ft_substr(s1, start, len));
}
