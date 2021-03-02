//
// Created by Аида Сайдашева on 08.02.2021.
//

#include "cub.h"

void	ft_check_error(int i)
{
	if (i == 0)
		write(1, "Malloc error\n", 13);
	if (i == 1)
		write(1, "Wrong resolution\n", 17);
	if (i == 2)
		write(1, "No map params\n", 14);
	if (i == 3)
		write(1, "Wrong texture\n", 14);
	if (i == 4)
		write(1, "Wrong color\n", 12);
	if (i == 5)
		write(1, "Wrong EOL\n", 10);
	if (i == 6)
		write (1, "Wrong map params\n", 17);
	if (i == 7)
		write(1, "Wrong map\n", 10);
	exit (0);
}