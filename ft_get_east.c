//
// Created by Аида Сайдашева on 09.02.2021.
//
#include "cub.h"

void	ft_get_east(char *line, t_struct *params, int i)
{
	int start;

	if (params->ea != NULL)
		ft_check_error(3);
	while (line[i] == ' ' && line[i])
		i++;
	start = i;
	while (line[i])
		i++;
	i -= 1;
	while (line[i] == ' ')
		i--;
	if (line[i] != 'm' || line[i - 1] != 'p' || line[i - 2] != 'x' || line[i - 3] != '.')
		ft_check_error(3);
	if (!(params->ea = ft_substr((const char *)line, start, i - start + 1)))
		ft_check_error(0);
	ft_check_file(params->ea);
	params->flag += 1;
}