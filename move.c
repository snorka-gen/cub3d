//
// Created by Florinda Cassey on 4/28/21.
//
#include "cub.h"

void	press_s(t_all *all)
{
	double tempX;
	double tempY;

	tempX = all->map->playerx - all->map->dir_x * 2 * MOVESPEED;
	tempY = all->map->playery - all->map->dir_y * 2 * MOVESPEED;
	if (all->map->map[(int)tempX][(int)all->map->playery] != '1')
		if (all->map->map[(int)tempX][(int)all->map->playery] != '2')
			all->map->playerx -= all->map->dir_x *  MOVESPEED;
	if (all->map->map[(int)all->map->playerx][(int)tempY] != '1')
		if (all->map->map[(int)all->map->playerx][(int)tempY] != '2')
			all->map->playery -= all->map->dir_y  * MOVESPEED;
	draw_map(all);
}

void	press_w(t_all *all)
{
	double tempX;
	double tempY;

	tempX = all->map->playerx + all->map->dir_x * 2 * MOVESPEED;
	tempY = all->map->playery + all->map->dir_y * 2 * MOVESPEED;
	if (all->map->map[(int)tempX][(int)all->map->playery] != '1')
		if (all->map->map[(int)tempX][(int)all->map->playery] != '2')
			all->map->playerx += all->map->dir_x *  MOVESPEED;
	if (all->map->map[(int)all->map->playerx][(int)tempY] != '1')
		if (all->map->map[(int)all->map->playerx][(int)tempY] != '2')
			all->map->playery += all->map->dir_y  * MOVESPEED;
	draw_map(all);
}

void	press_right(t_all *all)
{
	double speed;
	double oldDirX;
	double oldPlaneX;

	speed = 0.0872665;
	oldDirX = all->map->dir_x;
	oldPlaneX = all->map->planeX;
	all->map->dir_x = all->map->dir_x * cos(-speed) - all->map->dir_y * sin(-speed);
	all->map->dir_y = oldDirX * sin(-speed) + all->map->dir_y * cos(-speed);
	all->map->planeX = all->map->planeX * cos(-speed) - all->map->planeY * sin(-speed);
	all->map->planeY = oldPlaneX * sin(-speed) + all->map->planeY * cos(-speed);
	draw_map(all);
}

void	press_left(t_all *all)
{
	double speed;
	double oldDirX;
	double oldPlaneX;

	speed = 0.0872665;
	oldDirX = all->map->dir_x;
	oldPlaneX = all->map->planeX;
	all->map->dir_x = all->map->dir_x * cos(speed) - all->map->dir_y * sin(speed);
	all->map->dir_y = oldDirX * sin(speed) + all->map->dir_y * cos(speed);
	all->map->planeX = all->map->planeX * cos(speed) - all->map->planeY * sin(speed);
	all->map->planeY = oldPlaneX * sin(speed) + all->map->planeY * cos(speed);
	draw_map(all);
}
