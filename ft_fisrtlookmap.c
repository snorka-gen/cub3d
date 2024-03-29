/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fisrtlookmap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassey <fcassey@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 11:52:00 by fcassey           #+#    #+#             */
/*   Updated: 2021/05/02 11:52:02 by fcassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	ft_first_line(int fd, t_map *map)
{
	int		flag;
	char	*line;
	int		i;

	flag = 0;
	while (flag == 0)
	{
		i = 0;
		if (!(line = ft_gnl(fd, map)))
			ft_check_error("Something get wrong with map\n");
		while (line[i] == ' ' && line[i])
			i++;
		if (line[i] != '1' && line[i])
			ft_check_error("Something get wrong with map\n");
		if (line[i] == '1')
		{
			ft_player_look(map, line);
			map->len = ft_strlen(line);
			map->count = 1;
			flag = 1;
		}
		free(line);
	}
}

void		ft_fisrtlookmap(int fd, t_map *map)
{
	char	*line;

	ft_first_line(fd, map);
	while ((line = ft_gnl(fd, map)))
	{
		ft_maxlen(map, ft_strlen(line));
		ft_player_look(map, line);
		map->count++;
		free(line);
	}
	if (map->player != 1)
		ft_check_error("Is there ONE player?\n");
}
