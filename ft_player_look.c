/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_look.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassey <fcassey@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 11:53:44 by fcassey           #+#    #+#             */
/*   Updated: 2021/05/02 11:53:46 by fcassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void pov(t_map *map, char c)
{
	if (c == 'N')
	{
		map->planeX = 0;
		map->planeY = 0.66;
		map->dir_x = -1;
		map->dir_y = 0;
	}
	if (c == 'S')
	{
		map->planeX = 0;
		map->planeY = -0.66;
		map->dir_x = 1;
		map->dir_y = 0;
	}
	if (c == 'E')
	{
		map->planeX = 0.66;
		map->planeY = 0;
		map->dir_x = 0;
		map->dir_y = 1;
	}
	if (c == 'W')
	{
		map->planeX = -0.66;
		map->planeY = 0;
		map->dir_x = 0;
		map->dir_y = -1;
	}
}

void ft_player_look(t_map *map, char *line)
{
	int i;

	i = 0;
	if (!line)
		return ;
	while (line[i]) {
		if (!(ft_strchr("012NSEW ", line[i])))
			ft_check_error("Wrong object on map!\n");
		if (line[i] == '2')
			map->sprite++;
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E')
		{
			map->player++;
			pov(map, line[i]);
			map->playerx = map->count + 0.5;
			map->playery = i + 0.5;
		}
		i++;
	}
}
