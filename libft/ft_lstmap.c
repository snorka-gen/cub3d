/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassey <fcassey@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:12:52 by fcassey           #+#    #+#             */
/*   Updated: 2020/11/12 23:15:12 by fcassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *newlist;
	t_list *tmp;

	if (!lst || !f)
		return (NULL);
	if (!(newlist = ft_lstnew(f(lst->content))))
		return (NULL);
	lst = lst->next;
	tmp = newlist;
	while (lst)
	{
		if (!(tmp->next = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		lst = lst->next;
		tmp = tmp->next;
	}
	return (newlist);
}
