/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassey <fcassey@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 14:43:20 by fcassey           #+#    #+#             */
/*   Updated: 2020/11/04 18:39:28 by fcassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *str;
	char b;

	b = (char)c;
	str = (char *)s;
	while (*str != '\0' && (*str != b))
		str++;
	if (*str == b)
		return (str);
	return (NULL);
}
