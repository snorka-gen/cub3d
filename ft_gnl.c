//
// Created by Аида Сайдашева on 10.02.2021.
//

#include "cub.h"

char	*ft_gnl_par(int fd)
{
	char *line;

	if (get_next_line(fd, &line) < 1)
		ft_check_error(0);
	return (line);
}

char 	*ft_gnl(int fd, t_map *map)
{
	char	*line;
	int		i;

	i = get_next_line(fd, &line);
	if (i == -1)
		ft_check_error(0);
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