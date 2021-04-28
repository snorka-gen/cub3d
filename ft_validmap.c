//
// Created by Аида Сайдашева on 23.02.2021.
//

#include "cub.h"

static void	ft_topbot(t_map *map)
{
	int i;

	i = 0;
	while(map->map[0][i])
	{
		if (map->map[0][i] != ' ' && map->map[0][i] != '1')
			ft_check_error("Not enough walls\n");
		i++;
	}
	i = 0;
	while (map->map[map->count - 1][i])
	{
		if (map->map[map->count - 1][i] != ' ' && map->map[map->count - 1][i] != '1')
			ft_check_error("Not enough walls\n");
		i++;
	}
}

static void	ft_check_perimetr(t_map *map)
{
	int i;

	ft_topbot(map);
	i = 0;
	while (i < map->count)
	{
		if (map->map[i][0] != ' ' && map->map[i][0] != '1')
			ft_check_error("Not enough walls\n");
		i++;
	}
	i = 0;
	while (i < map->count)
	{
		if (map->map[i][map->len] != ' ' && map->map[i][map->len] != '1')
			ft_check_error("Not enough walls\n");
		i++;
	}
}

static void ft_hateful_eight(char **line, int i, int j)
{
	if (line[i][j] != '0' && line[i][j] != '2')
		line[i][j] = '0';
	if (line[i - 1][j - 1] == ' ' || line[i - 1][j] == ' ' ||
	line[i - 1][j + 1] == ' ' || line[i][j - 1] == ' ' ||
	line[i][j + 1] == ' ' || line[i + 1][j - 1] == ' ' ||
	line[i + 1][j] == ' ' || line[i + 1][j + 1] == ' ') {
		ft_check_error("Wrong map\n");
	}
}

void	ft_validmap(t_map *map)
{
	int i;
	int j;
	int x;

	map->sp = malloc(sizeof(t_sprite));
	if (map->sp == NULL)
		ft_check_error("Malloc Error\n");
	i = 1;
	x = 0;
	ft_check_perimetr(map);
	while (i < map->count - 1)
	{
		j = 1;
		while (j < map->len)
		{
			if (map->map[i][j] == '2')
			{
				map->sp[x].x = i;
				map->sp[x].y = j;
				x++;
			}
			if (map->map[i][j] != '1' && map->map[i][j] != ' ')
				ft_hateful_eight(map->map, i , j);
			j++;
		}
		i++;
	}
}