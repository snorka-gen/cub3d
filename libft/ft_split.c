/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassey <fcassey@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:21:37 by fcassey           #+#    #+#             */
/*   Updated: 2020/11/12 21:31:07 by fcassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		words(char *s, char c)
{
	int count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static char		*fillstr(char *s, char c)
{
	char	*str;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (!(str = (char *)malloc(i + 1)))
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static void		*memerror(char **split, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		free(split[j]);
		j++;
	}
	free(split);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**split;
	int		count;
	int		i;

	if (!s)
		return (NULL);
	count = words((char *)s, c);
	i = 0;
	if (!(split = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	while (i < count)
	{
		while (*s == c && *s)
			s++;
		if (!(split[i] = fillstr((char *)s, c)))
			memerror(split, i);
		while (*s != c && *s)
			s++;
		i++;
	}
	split[i] = NULL;
	return (split);
}
