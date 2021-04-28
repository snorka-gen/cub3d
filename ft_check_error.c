//
// Created by Аида Сайдашева on 08.02.2021.
//

#include "cub.h"

void	ft_check_error(char *str)
{
	write(1, "Error\n", 6);
	write(1, str, ft_strlen(str));
	exit (0);
}