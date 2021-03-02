/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassey <fcassey@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:33:32 by fcassey           #+#    #+#             */
/*   Updated: 2020/11/03 13:59:39 by fcassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *s1;
	char *s2;

	s1 = (char *)dst;
	s2 = (char *)src;
	if (!n || (!src && !dst))
		return (dst);
	while (n--)
		*s1++ = *s2++;
	return (dst);
}
