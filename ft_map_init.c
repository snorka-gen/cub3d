//
// Created by Аида Сайдашева on 10.02.2021.
//

#include "cub.h"

t_map	*ft_map_init()
{
	t_map *map;

	if (!(map = malloc(sizeof (t_map))))
		ft_check_error("Malloc Error\n");
	map->len = 0;
	map->count = 0;
	map->player = 0;
	map->map = NULL;
	map->sprite = 0;
	return (map);
}