/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassey <fcassey@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:47:17 by fcassey           #+#    #+#             */
/*   Updated: 2020/11/04 18:38:41 by fcassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char *s1;
	char k;

	k = (char)c;
	s1 = (char *)s;
	while (n--)
	{
		if (*s1 == k)
			return (s1);
		s1++;
	}
	return (NULL);
}
