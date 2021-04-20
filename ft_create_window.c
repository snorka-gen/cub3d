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
//	float distance = (all->params->x / 2) / tan(0.523599);
	size_t column = (SCALE/ (c * cos(all->ray->angle - all->map->playera))) * all->ray->distance;
//	size_t column = 100;
//	printf("column %zu\n", column);
//	printf("c %f, corrected c %f\n", c, c * cos(all->ray->angle - all->map->playera));
//	printf("%f %zu, c %f\n", distance, column, c);
	int starty = all->params->y/2 - column/2;

	int i;
	i = 0;
	while (i < starty)
		my_mlx_pixel_put(all->img, x, i++, all->params->up);
	while (i < starty + column && i < all->params->y)
		my_mlx_pixel_put(all->img, x, i++, 0xffffff);
	while (i < all->params->y)
		my_mlx_pixel_put(all->img, x, i++, all->params->down);
}

float opt(t_all *all)
{
	float c;
	c = 0;
	float cosinus = cos(all->ray->angle);
	float sinus = sin(all->ray->angle);
	while (all->map->map[(int) (all->ray->x/SCALE)][(int) (all->ray->y/SCALE)] != '1') {
		all->ray->x = all->map->playerx + c * cosinus;
		all->ray->y = all->map->playery + c * sinus;
		c += 5;
	}
	if (c >= 10)
		c -= 10;
	all->ray->x -= (5 * cosinus);
	all->ray->y -= (5 * sinus);
	while (all->map->map[(int) (all->ray->x/SCALE)][(int) (all->ray->y/SCALE)] != '1') {
		all->ray->x = all->map->playerx + c * cosinus;
		all->ray->y = all->map->playery + c * sinus;
		c += 1;
	}
	c -= 2;
	all->ray->x -= cosinus;
	all->ray->y -= sinus;
	while (all->map->map[(int) (all->ray->x/SCALE)][(int) (all->ray->y/SCALE)] != '1') {
		all->ray->x = all->map->playerx + c * cosinus;
		all->ray->y = all->map->playery + c * sinus;
		c += 0.05;
	}
	if (all->ray->x < all->ray->y)
		all->map->side = 0;
	else
		all->map->side = 1;
	return (c - .05);
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
	float c;
	while (i < all->params->x) {
		all->ray->angle = all->map->playera + 0.523 - i * (1.047/all->params->x);
		all->ray->x = all->map->playerx;
		all->ray->y = all->map->playery;
		c = opt(all);
		put_the_wall(all, opt(all), i);
		i++;
	}
	mlx_put_image_to_window(all->img->mlx, all->img->win, all->img->img, 0, 0);
}
//static void	steps_to_wall(t_all *all, int key)
//{
//
//}

static void press_s(t_all *all)
{
	float x;
	float y;
	int i;

	i = 0;
	while (i < SCALE/4) {
		mlx_clear_window(all->img->mlx, all->img->win);
		x = all->map->playerx - cos(all->map->playera);
		y = all->map->playery - sin(all->map->playera);
		if (all->map->map[(int) x / SCALE][(int) y / SCALE] != '1') {
			all->map->playerx = x;
			all->map->playery = y;
		}
		else
			i = SCALE/4;

		draw_map(all);
		i++;
	}
}

static void press_w(t_all *all)
{
	float x;
	float y;
	int i;

	i = 0;
//	while (i < 16) {
//		mlx_clear_window(all->img->mlx, all->img->win);
//		x = all->map->playerx + cos(all->map->playera) * 2;
//		y = all->map->playery + sin(all->map->playera) * 2;
//		if (all->map->map[(int) x / 128][(int) y / 128] != '1') {
//			all->map->playerx = x;
//			all->map->playery = y;
//		}
//		else
//			i = 16;
//		draw_map(all);
//		i++;
//	}
	while (i < SCALE/4) {
		mlx_clear_window(all->img->mlx, all->img->win);
		x = all->map->playerx + cos(all->map->playera);
		y = all->map->playery + sin(all->map->playera);
		if (all->map->map[(int) (x) / SCALE][(int) y / SCALE] != '1') {
			all->map->playerx = x;
			all->map->playery = y;
		}
		else {
			i = SCALE/4;
//			printf("!!WALL x:%d y:%d\n", (int)all->map->playerx/128, (int)all->map->playery/128);
		}
		draw_map(all);
		i++;
	}
}


int key_hook(int key, t_all *all) {
//		mlx_clear_window(all->img->mlx, all->img->win);
		if (key == 13)
			press_w(all);
		if (key == 1)
			press_s(all);
		if (key == 0) {
			all->map->playera += 0.261799;
			draw_map(all);
		}
		if (key == 2) {
			all->map->playera -= 0.261799;
			draw_map(all);
		}
		if (key == 6) {
			float angle;
			if (all->map->playera >= 0)
				angle = fmod(all->map->playera ,(2*3.141593));
			else
				angle = fmod(all->map->playera ,(2*3.141593)) + (2*3.141593);
			printf("%f\n", angle);
		}
		if (key == 53) {
			mlx_destroy_window(all->img->mlx, all->img->win);
			exit(0);
	}
//		draw_map(all);
		return (0);
	}

	void ft_create_window(t_all *all)
	{
		all->img->mlx = mlx_init();
		all->img->win = mlx_new_window(all->img->mlx, all->params->x, all->params->y, "cub3D");
		all->img->img = mlx_new_image(all->img->mlx, all->params->x, all->params->y);
		all->img->addr = mlx_get_data_addr(all->img->img, &all->img->bits_per_pixel, &all->img->line_length,
										   &all->img->endian);
		all->ray->distance = (all->params->x / 2) / tan(0.523599);
		draw_map(all);
		mlx_hook(all->img->win, 2, (1L << 0), &key_hook, all);

		mlx_loop(all->img->mlx);
	}
