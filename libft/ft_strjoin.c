/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassey <fcassey@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:40:35 by fcassey           #+#    #+#             */
/*   Updated: 2020/11/04 19:28:52 by fcassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	j = 0;
	while (*s1 != '\0')
	{
		str[j] = *s1;
		j++;
		s1++;
	}
	while (*s2 != '\0')
	{
		str[j] = *s2;
		j++;
		s2++;
	}
	str[j] = '\0';
	return (str);
}
