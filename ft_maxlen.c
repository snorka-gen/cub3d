//
// Created by Аида Сайдашева on 10.02.2021.
//

#include "cub.h"

void	ft_maxlen(t_map *map, int len)
{
	if (map->len < len)
		map->len = len;
}