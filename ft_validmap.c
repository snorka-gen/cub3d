/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassey <fcassey@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 11:54:10 by fcassey           #+#    #+#             */
/*   Updated: 2021/05/02 11:54:11 by fcassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	ft_topbot(t_map *map)
{
	int i;

	i = 0;
	while (map->map[0][i])
	{
		if (map->map[0][i] != ' ' && map->map[0][i] != '1')
			ft_check_error("Not enough walls\n");
		i++;
	}
	i = 0;
	while (map->map[map->count - 1][i])
	{
		if (map->map[map->count - 1][i] != ' ' &&
			map->map[map->count - 1][i] != '1')
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
		{
			printf("|%s| i = %d\n", map->map[i], i);
			ft_check_error("Not enough walls?\n");
		}
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

static void	ft_hateful_eight(char **line, int i, int j)
{
	if (line[i][j] != '0' && line[i][j] != '2')
		line[i][j] = '0';
	if (line[i - 1][j - 1] == ' ' || line[i - 1][j] == ' ' ||
	line[i - 1][j + 1] == ' ' || line[i][j - 1] == ' ' ||
	line[i][j + 1] == ' ' || line[i + 1][j - 1] == ' ' ||
	line[i + 1][j] == ' ' || line[i + 1][j + 1] == ' ')
	{
		ft_check_error("Wrong map\n");
	}
}

static int	sprites(t_map *map, int x, int i, int j)
{
	if (map->map[i][j] == '2')
	{
		map->sp[x].x = i;
		map->sp[x].y = j;
		x++;
	}
	return (x);
}

void		ft_validmap(t_map *map)
{
	int i;
	int j;
	int x;

	map->sp = malloc(sizeof(t_sprite) * map->sprite);
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
			x = sprites(map, x, i, j);
			if (map->map[i][j] != '1' && map->map[i][j] != ' ')
				ft_hateful_eight(map->map, i, j);
			j++;
		}
		i++;
	}
}
