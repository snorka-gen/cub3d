//
// Created by Аида Сайдашева on 02.03.2021.
//
#include "cub.h"



void	press_d(t_all *all)
{
	double tempX;
	double tempY;

	tempX = all->map->playerx + all->map->dir_y * 2 * MOVESPEED;
	tempY = all->map->playery - all->map->dir_x * 2 * MOVESPEED;
	if (all->map->map[(int)tempX][(int)all->map->playery] != '1')
		if (all->map->map[(int)tempX][(int)all->map->playery] != '2')
		all->map->playerx += all->map->dir_y * MOVESPEED;
	if (all->map->map[(int)all->map->playerx][(int)tempY] != '1')
		if (all->map->map[(int)all->map->playerx][(int)tempY] != '2')
		all->map->playery -= all->map->dir_x * MOVESPEED;
	draw_map(all);
}

void	press_a(t_all *all)
{
	double tempX;
	double tempY;

	tempX = all->map->playerx - all->map->dir_y * 2 * MOVESPEED;
	tempY = all->map->playery + all->map->dir_x * 2 * MOVESPEED;
	if (all->map->map[(int)tempX][(int)all->map->playery] != '1')
		if (all->map->map[(int)tempX][(int)all->map->playery] != '2')
		all->map->playerx -= all->map->dir_y * MOVESPEED;
	if (all->map->map[(int)all->map->playerx][(int)tempY] != '1')
		if (all->map->map[(int)all->map->playerx][(int)tempY] != '2')
		all->map->playery += all->map->dir_x * MOVESPEED;
	draw_map(all);
}

int		key_hook(int key, t_all *all)
{
	if (key == 13)
		press_w(all);
	if (key == 1)
		press_s(all);
	if (key == 124)
		press_right(all);
	if (key == 123)
		press_left(all);
	if (key == 2)
		press_d(all);
	if (key == 0)
		press_a(all);
	if (key == 53) {
		mlx_destroy_window(all->img->mlx, all->img->win);
		exit(0);
	}
	return (0);
}

void	ft_create_window(t_all *all) {
	all->img->mlx = mlx_init();
	all->img->win = mlx_new_window(all->img->mlx, all->params->x, all->params->y, "cub3D");
	all->img->img = mlx_new_image(all->img->mlx, all->params->x, all->params->y);
	all->img->addr = mlx_get_data_addr(all->img->img, &all->img->bits_per_pixel, &all->img->line_length,
									   &all->img->endian);
	texture_test(all);
	all->map->dist = (all->params->x / 2) / tan(0.575959);
	draw_map(all);
	mlx_hook(all->img->win, 2, (1L << 0), &key_hook, all);
	mlx_loop(all->img->mlx);
}
