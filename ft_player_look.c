//
// Created by Аида Сайдашева on 23.02.2021.
//
#include "cub.h"

void ft_player_look(t_map *map, char *line)
{
	int i;

	i = 0;
	if (!line)
		return ;
	while (line[i]) {
		if (!(ft_strchr("012NSEW ", line[i])))
			ft_check_error(7);
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E')
		{
			map->player++;
			map->playerx = map->count * 10;
			map->playery = i * 10;
		}
		i++;
	}
}