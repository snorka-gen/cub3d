//
// Created by Аида Сайдашева on 09.02.2021.
//

#include "cub.h"

void	ft_check_file(char *path)
{
	int fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_check_error("Is mapfile OK?\n");
	close (fd);
}