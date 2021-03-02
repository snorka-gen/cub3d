/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassey <fcassey@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 14:58:44 by fcassey           #+#    #+#             */
/*   Updated: 2020/11/08 15:16:13 by fcassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *newlist;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	newlist = ft_lstlast(*lst);
	newlist->next = new;
	new->next = NULL;
}
