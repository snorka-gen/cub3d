/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassey <fcassey@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:29:15 by fcassey           #+#    #+#             */
/*   Updated: 2021/02/09 21:55:31 by aidasajdaseva    ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checklen(char const *s, unsigned int start, size_t len)
{
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	return (len);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (!(str = (char *)malloc(checklen(s, start, len) + 1)))
		return (NULL);
	while (s[i])
	{
		if (i >= start && i < start + len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}
