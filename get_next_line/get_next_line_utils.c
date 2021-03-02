/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassey <fcassey@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:46:29 by fcassey           #+#    #+#             */
/*   Updated: 2021/02/03 18:07:54 by aidasajdaseva    ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		new_line_is_here(char *s)
{
	if (s)
		while (*s)
		{
			if (*s == '\n')
				return (1);
			s++;
		}
	return (0);
}

int		ft_strlen_gnl(char *s)
{
	int i;

	i = 0;
	if (s)
		while (s[i])
			i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*s;
	int		j;
	int		i;

	if (!(s = (char *)malloc(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1)))
		return (NULL);
	j = 0;
	i = 0;
	if (s1)
	{
		while (s1[i] != '\0')
			s[j++] = s1[i++];
		free(s1);
	}
	while (*s2 != '\0')
		s[j++] = *s2++;
	s[j] = '\0';
	return (s);
}

char	*get_line(char *s)
{
	int		i;
	char	*line;

	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	if (!(line = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i] != '\n' && s[i])
	{
		line[i] = s[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_str(char *s)
{
	char	*newstr;
	int		i;
	int		j;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (ft_strlen_gnl(s + i) == 0)
	{
		free(s);
		return (NULL);
	}
	if (!(newstr = (char *)malloc(sizeof(char) * (ft_strlen_gnl(s + i) + 1))))
		return (NULL);
	i++;
	j = 0;
	while (s[i])
		newstr[j++] = s[i++];
	newstr[j] = '\0';
	free(s);
	return (newstr);
}
