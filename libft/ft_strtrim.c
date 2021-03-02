/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassey <fcassey@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:46:02 by fcassey           #+#    #+#             */
/*   Updated: 2020/11/04 19:24:29 by fcassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		checker(const char *s1, const char *set)
{
	int i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (ft_strchr(set, s1[i]))
			i++;
		else
			return (1);
	}
	return (0);
}

static int		nachalo(const char *s1, const char *set)
{
	int start;

	start = 0;
	while (ft_strchr(set, s1[start]))
		start++;
	return (start);
}

static int		konec(const char *s1, const char *set)
{
	int end;

	end = ft_strlen(s1);
	while (ft_strchr(set, s1[end]))
		end--;
	return (end);
}

static char		*resultstr(char const *s1, char *str, int start, int end)
{
	int i;

	i = 0;
	while ((i + start) <= end)
	{
		str[i] = s1[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;
	char			*str;

	if (!s1 || !set)
		return (NULL);
	if (checker(s1, set))
	{
		start = nachalo(s1, set);
		end = konec(s1, set);
		if (!(str = (char *)malloc(end - start + 2)))
			return (NULL);
		str = resultstr(s1, str, start, end);
	}
	else
	{
		if (!(str = (char *)malloc(1)))
			return (NULL);
		str[0] = '\0';
	}
	return (str);
}
