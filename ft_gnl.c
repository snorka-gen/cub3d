/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassey <fcassey@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 11:53:16 by fcassey           #+#    #+#             */
/*   Updated: 2021/05/02 11:53:17 by fcassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*ft_gnl_par(int fd)
{
	char *line;

	if (get_next_line(fd, &line) < 1)
		ft_check_error("Something wrong with GNL\n Is there map in mapfile?\n");
	return (line);
}

char	*ft_gnl(int fd, t_map *map)
{
	char	*line;
	int		i;

	i = get_next_line(fd, &line);
	if (i == -1)
		ft_check_error("Something wrong with GNL\n");
	if (i == 0)
	{
		ft_player_look(map, line);
		ft_maxlen(map, ft_strlen(line));
		map->count++;
		free(line);
		return (NULL);
	}
	return (line);
}
