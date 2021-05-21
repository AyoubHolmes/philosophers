/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:17:47 by aboulbaz          #+#    #+#             */
/*   Updated: 2019/11/01 13:17:48 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *t))
{
	t_list *p;
	t_list *q;

	if (*lst != NULL && del)
	{
		p = *lst;
		while (p != NULL)
		{
			q = p;
			p = p->next;
			del(q->content);
			free(q);
		}
		*lst = NULL;
	}
}
