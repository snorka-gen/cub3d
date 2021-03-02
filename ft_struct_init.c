//
// Created by Аида Сайдашева on 08.02.2021.
//

#include "cub.h"

t_struct *ft_struct_init()
{
	t_struct *params;

	if (!(params = malloc(sizeof (t_struct))))
		ft_check_error(0);
	params->y = 0;
	params->x = 0;
	if (!(params->sky = malloc(sizeof (int) * 3)))
		ft_check_error(0);
	params->sky[0] = -1;
	if (!(params->floor = malloc(sizeof (int) * 3)))
		ft_check_error(0);
	params->floor[0] = -1;
	params->no = NULL;
	params->we = NULL;
	params->so = NULL;
	params->ea = NULL;
	params->s = NULL;
	return (params);
}