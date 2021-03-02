/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassey <fcassey@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:44:26 by fcassey           #+#    #+#             */
/*   Updated: 2020/11/04 18:39:01 by fcassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s1;
	char	*s2;
	size_t	i;

	s1 = (char *)dst;
	s2 = (char *)src;
	if (!dst && !src)
		return (dst);
	if (src < dst)
	{
		i = len;
		while (i-- > 0)
			s1[i] = s2[i];
	}
	else
	{
		i = -1;
		while (++i < len)
			s1[i] = s2[i];
	}
	return (dst);
}
