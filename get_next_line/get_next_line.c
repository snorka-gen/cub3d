/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassey <fcassey@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:42:57 by fcassey           #+#    #+#             */
/*   Updated: 2021/02/04 14:03:17 by aidasajdaseva    ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		check(char *str, int readed)
{
	if (readed == 0)
		return (0);
	if (!str)
		return (-1);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	int			readed;
	char		*buff;
	static char	*str;

	if (!line)
		return (-1);
	if (!(buff = (char *)malloc(sizeof(char) * (7))))
		return (-1);
	readed = 1;
	while (readed != 0 && !new_line_is_here(str))
	{
		if ((readed = read(fd, buff, 6)) < 0)
			return (-1);
		buff[readed] = '\0';
		if (!(str = ft_strjoin_gnl(str, buff)))
			return (-1);
	}
	free(buff);
	if (!(*line = get_line(str)))
		return (-1);
	str = get_str(str);
	return (check(str, readed));
}
