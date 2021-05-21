/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:08:16 by aboulbaz          #+#    #+#             */
/*   Updated: 2019/11/09 14:08:18 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *p;
	t_list *t;

	if (!lst || !f)
		return (NULL);
	p = NULL;
	while (lst != NULL)
	{
		if (!(t = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&p, del);
			return (NULL);
		}
		ft_lstadd_back(&p, t);
		lst = lst->next;
	}
	return (p);
}
