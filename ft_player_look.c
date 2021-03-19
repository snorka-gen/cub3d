//
// Created by Аида Сайдашева on 23.02.2021.
//
#include "cub.h"

static void pov(t_map *map, char c)
{
	if (c == 'N')
		map->playera = 3.1415926535897;
	if (c == 'S')
		map->playera = 0;
	if (c == 'E')
		map->playera = 3.1415926535897 / 2;
	if (c == 'W')
		map->playera = (3 * 3.1415926535897) / 2;
}

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
			pov(map, line[i]);
			map->playerx = map->count * 128 + 64;
			map->playery = i * 128 + 64;
		}
		i++;
	}
}