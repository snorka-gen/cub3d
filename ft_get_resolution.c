//
// Created by Аида Сайдашева on 08.02.2021.
//

#include "cub.h"

static int ft_get_x(char *line, t_struct *params, int i)
{

	while (line[i] == ' ' && line[i])
		i++;
	if (ft_strchr("123456789", line[i]))
		while (ft_isdigit(line[i]))
		{
			params->x = params->x * 10 + (line[i] - 48);
			if (params->x > 2440)
				params->x = 2440;
			i++;
		}
	else
		ft_check_error(1);
	return (i);
}

static int ft_get_y(char *line, t_struct *params, int i)
{
	while (line[i] == ' ' && line[i])
		i++;
	if (ft_strchr("123456789", line[i]))
		while (ft_isdigit(line[i]))
		{
			params->y = params->y * 10 + (line[i] - 48);
			if (params->y > 1440)
				params->y = 1440;
			i++;
		}
	else
		ft_check_error(1);
	return (i);
}

void ft_get_resolution(char *line, t_struct *params, int i)
{
	if (params->x != 0)
		ft_check_error(1);
	i = ft_get_x(line, params, i);
	i = ft_get_y(line, params, i);
	ft_endofline(line, i);
	params->flag += 2;
}