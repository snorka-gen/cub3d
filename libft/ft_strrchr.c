/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassey <fcassey@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 13:43:47 by fcassey           #+#    #+#             */
/*   Updated: 2020/11/04 18:35:54 by fcassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char b;
	char *str;

	b = (char)c;
	if (!(ft_strchr(s, c)))
		return (NULL);
	str = (char *)s + ft_strlen(s);
	while (str && (*str != b))
		str--;
	return (str);
}
