/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secondlookmap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassey <fcassey@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 11:53:52 by fcassey           #+#    #+#             */
/*   Updated: 2021/05/02 11:53:53 by fcassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	ft_mapline(t_map *map, char *line, int i)
{
	int j;

	j = 0;
	if (!(map->map[i] = ft_spacealloc(map->len + 1, 1)))
		ft_check_error("Malloc Error\n");
	while (line[j])
	{
		map->map[i][j] = line[j];
		j++;
	}
	if (line[0] == '\0')
		map->map[i][0] = ' ';
}

static void	ft_first_line(int fd, t_map *map)
{
	int		flag;
	char	*line;
	int		i;

	flag = 0;
	while (flag == 0)
	{
		i = 0;
		if (get_next_line(fd, &line) != 1)
			ft_check_error("Where is map?\n");
		while (line[i] == ' ' && line[i])
			i++;
		if (line[i] == '1' && line[i])
			flag = 1;
		if (flag == 0)
			free(line);
	}
	ft_mapline(map, line, 0);
	free(line);
}

void		ft_secondlookmap(int fd, t_map *map)
{
	char	*line;
	int		i;

	if (!(map->map = malloc(sizeof(char *) * map->count)))
		ft_check_error("Malloc Error\n");
	i = 1;
	ft_first_line(fd, map);
	while (get_next_line(fd, &line))
	{
		ft_mapline(map, line, i++);
		free(line);
	}
	ft_mapline(map, line, i++);
	free(line);
	map->map[i] = NULL;
	ft_validmap(map);
}
