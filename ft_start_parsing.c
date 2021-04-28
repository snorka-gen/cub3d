//
// Created by Аида Сайдашева on 08.02.2021.
//
#include "cub.h"

void	ft_start_parsing(char *line, t_struct *params, int i)
{
	if (line[i] == 'R' && (line[i + 1] == ' ' || ft_isalnum(line[i + 1])))
		ft_get_resolution(line, params, i + 2);
	else if (line[i] == 'N' && line[i + 1] == 'O' && (line[i + 2] == ' ' || line[i + 2] == '.'))
		ft_get_north(line, params, i + 2);
	else if (line[i] == 'S' && line[i + 1] == 'O' && (line[i + 2] == ' ' || line[i + 2] == '.'))
		ft_get_south(line, params, i + 2);
	else if (line[i] == 'W' && line[i + 1] == 'E' && (line[i + 2] == ' ' || line[i + 2] == '.'))
		ft_get_west(line, params, i + 2);
	else if (line[i] == 'E' && line[i + 1] == 'A' && (line[i + 2] == ' ' || line[i + 2] == '.'))
		ft_get_east(line, params, i + 2);
	else if (line[i] == 'S' && (line[i + 1] == ' ' || line[i + 1] == '.'))
		ft_get_sprite(line, params, i + 1);
	else if (line[i] == 'F' && (line[i + 1] == ' ' || ft_isalnum(line[i + 1])))
		ft_get_floor(line, params, i + 2);
	else if (line[i] == 'C' && (line[i + 1] == ' ' || ft_isalnum(line[i + 1])))
		ft_get_ceiling(line, params, i + 2);
}
