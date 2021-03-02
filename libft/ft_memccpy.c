/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassey <fcassey@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:37:35 by fcassey           #+#    #+#             */
/*   Updated: 2020/11/01 21:27:49 by fcassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char *s1;
	char *s2;
	char k;

	k = (char)c;
	s1 = (char *)dst;
	s2 = (char *)src;
	while (n--)
	{
		*s1 = *s2;
		if (*s1 == k)
		{
			dst = s1 + 1;
			return (dst);
		}
		s1++;
		s2++;
	}
	return (NULL);
}
