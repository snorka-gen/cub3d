/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassey <fcassey@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 15:30:36 by fcassey           #+#    #+#             */
/*   Updated: 2020/11/08 17:38:45 by fcassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *tmp;
	t_list *tmp2;

	tmp = *lst;
	while (tmp)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		ft_lstdelone(tmp2, del);
	}
	*lst = NULL;
}
