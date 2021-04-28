//
// Created by Аида Сайдашева on 09.02.2021.
//
#include "cub.h"

void	ft_get_north(char *line, t_struct *params, int i)
{
	int start;

	if (params->no != NULL)
		ft_check_error("Too much textures....\n");
	while (line[i] == ' ' && line[i])
		i++;
	start = i;
	while (line[i])
		i++;
	i -= 1;
	while (line[i] == ' ')
		i--;
	if (line[i] != 'm' || line[i - 1] != 'p' || line[i - 2] != 'x' || line[i - 3] != '.')
		ft_check_error("it isn't XPM file! Please add XPM texture\n");
	if (!(params->no = ft_substr((const char *)line, start, i - start + 1)))
		ft_check_error("Malloc Error\n");
	ft_check_file(params->no);
	params->flag += 1;
}
