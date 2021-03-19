//
// Created by Аида Сайдашева on 02.03.2021.
//
#include "cub.h"
#include <math.h>

//


static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static void put_pixels(t_data *img, int x, int y, int color)
{
	int i;
	int j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			my_mlx_pixel_put(img, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void put_the_wall(t_all *all, float c, size_t x)
{
//	size_t column = all->params->y/(c/10 * cos(all->ray->angle - all->map->playera));
	float distance = (all->params->x / 2) / tan(0.523599);
	size_t column = (64 / (c * cos(all->ray->angle - all->map->playera))) * distance;
	printf("c %f, corrected c %f\n", c, c * cos(all->ray->angle - all->map->playera));
//	printf("%f %zu, c %f\n", distance, column, c);
	int starty = all->params->y/2 - column/2;
	int i;
	i = 0;
	while (i < starty)
		my_mlx_pixel_put(all->img, x, i++, all->params->up);
	while (i < starty + column)
		my_mlx_pixel_put(all->img, x, i++, 0xffffff);
	while (i < all->params->y)
		my_mlx_pixel_put(all->img, x, i++, all->params->down);
}

static void draw_map(t_all *all) {
	int x;
	int y;

	x = 0;
	// Отрисовка карты с положением игрока
//	while (all->map->map[x]) {
//		y = 0;
//		while (all->map->map[x][y]) {
//			if (all->map->map[x][y] == '1')
//				put_pixels(all->img, y * 10, x * 10, 0xffffff);
//			if (all->map->map[x][y] == '2')
//				put_pixels(all->img, y * 10, x * 10, 0xff0000);
//			if (all->map->map[x][y] == 'E' || all->map->map[x][y] == 'N' || all->map->map[x][y] == 'W' ||
//				all->map->map[x][y] == 'S')
//				put_pixels(all->img, y * 10, x * 10, all->params->down);
//			if (all->map->map[x][y] == '0')
//				put_pixels(all->img, y * 10, x * 10, all->params->down);
//			put_pixels(all->img, all->map->playery - 5, all->map->playerx - 5, 0x0000ff);
//			y++;
//		}
//		x++;
//	}
// Отрисовка луча "взгляда"
	size_t i = 0;
	while (i < all->params->x) {
		all->ray->angle = all->map->playera + 0.523 - i * (1.047/all->params->x);
		float c = 0;
		all->ray->x = all->map->playerx;
		all->ray->y = all->map->playery;
		while (all->map->map[(int) (all->ray->x/64)][(int) (all->ray->y/64)] != '1') {
			all->ray->x = all->map->playerx + c * cos(all->ray->angle);
			all->ray->y = all->map->playery + c * sin(all->ray->angle);
			c += 0.05;
//			my_mlx_pixel_put(all->img, all->ray->y, all->ray->x, 0x990099);
		}
		put_the_wall(all, c, i);
		i++;
	}
	mlx_put_image_to_window(all->img->mlx, all->img->win, all->img->img, 0, 0);
}

static void press_s(t_all *all)
{
	float x;
	float y;

	x = all->map->playerx - cos(all->map->playera)*10;
	y = all->map->playery - sin(all->map->playera)*10;
	if (all->map->map[(int)x/64][(int)y/64] != '1')
	{
		all->map->playerx = x;
		all->map->playery = y;
	}
}

static void press_w(t_all *all)
{
	float x;
	float y;

	x = all->map->playerx + cos(all->map->playera)*10;
	y = all->map->playery + sin(all->map->playera)*10;
	if (all->map->map[(int)x/64][(int)y/64] != '1')
	{
		all->map->playerx = x;
		all->map->playery = y;
	}
}


int key_hook(int key, t_all *all) {
		mlx_clear_window(all->img->mlx, all->img->win);
		if (key == 13)
			press_w(all);
		if (key == 1)
			press_s(all);
		if (key == 0)
			all->map->playera += 0.174533;
		if (key == 2)
			all->map->playera -= 0.174533;
		if (key == 53) {
			mlx_destroy_window(all->img->mlx, all->img->win);
			exit(0);
	}
		draw_map(all);
		return (0);
	}

	void ft_create_window(t_all *all)
	{
		all->img->mlx = mlx_init();
		all->img->win = mlx_new_window(all->img->mlx, all->params->x, all->params->y, "test");
		all->img->img = mlx_new_image(all->img->mlx, all->params->x, all->params->y);
		all->img->addr = mlx_get_data_addr(all->img->img, &all->img->bits_per_pixel, &all->img->line_length,
										   &all->img->endian);
		draw_map(all);
		mlx_hook(all->img->win, 2, (1L << 0), &key_hook, all);
		mlx_loop(all->img->mlx);
	}
