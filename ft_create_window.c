//
// Created by Аида Сайдашева on 02.03.2021.
//
#include "cub.h"

//

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static void texture_test(t_all *all)
{
	all->texture->img = mlx_xpm_file_to_image(all->img->mlx, all->params->no, &all->texture->width, &all->texture->height);
	all->texture->addr = mlx_get_data_addr(all->texture->img, &all->texture->bits_per_pixel, &all->texture->line_length,
										&all->texture->endian);
}

void get_tex_color(t_all *all, int x, int y)
{
	char *dst;
	dst = all->texture->addr + (y * all->texture->line_length + x * (all->texture->bits_per_pixel/8));
	all->texture->color = *(unsigned int *)dst;
}
void put_the_wall(t_all *all, float c, size_t x)
{
	size_t column = (SCALE/ c) * all->ray->distance;
	int starty = all->params->y/2 - column/2;
	if (starty < 0)
		starty = 0;
	int endy = column/2 + all->params->y/2;
	if (endy >= all->params->y)
		endy = all->params->y - 1;
	double step = 1.0  * all->texture->height/column;
	double texPos = (starty - all->params->y/2 + column/2) * step;
	int i;
	i = 0;
	while (i < starty)
		my_mlx_pixel_put(all->img, x, i++, all->params->up);
	while (i < endy && i < all->params->y)
	{
		int texY = (int)texPos & (all->texture->height - 1);
		texPos += step;
		get_tex_color(all, all->texture->texX, texY);
		my_mlx_pixel_put(all->img, x, i++, all->texture->color);
	}
	while (i < all->params->y)
		my_mlx_pixel_put(all->img, x, i++, all->params->down);
}

float opt(t_all *all) {
	float c;
	c = 0;
	float cosinus = cos(all->ray->angle);
	float sinus = sin(all->ray->angle);
	while (all->map->map[(int) (all->ray->x / SCALE)][(int) (all->ray->y / SCALE)] != '1') {
		c += 5;
		all->ray->x = all->map->playerx + c * cosinus;
		all->ray->y = all->map->playery + c * sinus;
	}
	if (c > 5)
	c -= 5;
	all->ray->x = all->map->playerx + c * cosinus;
	all->ray->y = all->map->playery + c * sinus;
	while (all->map->map[(int) (all->ray->x / SCALE)][(int) (all->ray->y / SCALE)] != '1') {
		c += 1;
		all->ray->x = all->map->playerx + c * cosinus;
		all->ray->y = all->map->playery + c * sinus;
	}
	c -= 1;
	all->ray->x = all->map->playerx + c * cosinus;
	all->ray->y = all->map->playery + c * sinus;
	while (all->map->map[(int) (all->ray->x / SCALE)][(int) (all->ray->y / SCALE)] != '1') {
		c += 0.05;
		all->ray->x = all->map->playerx + c * cosinus;
		all->ray->y = all->map->playery + c * sinus;
//		c += 0.0005;
	}
	c -= 0.05;
	int hitx = fmod(all->ray->x, SCALE);
	if (hitx <= 0)
		hitx = SCALE - hitx - 1;
	int hity = fmod(all->ray->y, SCALE);
	if (hity <= 0)
		hity = SCALE - hity - 1;
	if (hitx < hity)
	{
		all->map->side = 0;
		all->texture->texX = hitx;
	}
	else
	{
		all->map->side = 1;
		all->texture->texX = hity;
	}
	return (c * cos(all->ray->angle - all->map->playera));
}

static void draw_map(t_all *all) {
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

static void press_s(t_all *all)
{
	float x;
	float y;
	int i;
	float cosinus;
	float sinus;

	i = 0;
	cosinus = cos(all->map->playera);
	sinus = sin(all->map->playera);
	while (i < SCALE/4) {
//		mlx_clear_window(all->img->mlx, all->img->win);
		x = all->map->playerx - cosinus * 8;
		y = all->map->playery - sinus * 8;
		if (all->map->map[(int) x / SCALE][(int) y / SCALE] &&
				all->map->map[(int) x / SCALE][(int) y / SCALE] != '1') {
			all->map->playerx -= cosinus;
			all->map->playery -= sinus;
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
	float cosinus;
	float sinus;

	cosinus = cos(all->map->playera);
	sinus = sin(all->map->playera);
	i = 0;
	while (i < SCALE/4) {
//		mlx_clear_window(all->img->mlx, all->img->win);
		x = all->map->playerx + cosinus * 8;
		y = all->map->playery + sinus * 8;
		if (all->map->map[(int) (x) / SCALE][(int) y / SCALE] != '1') {
			all->map->playerx += cosinus;
			all->map->playery += sinus;
		}
		else {
			i = SCALE/4;
		}
		draw_map(all);
		i++;
	}
}


int key_hook(int key, t_all *all) {
		mlx_clear_window(all->img->mlx, all->img->win);
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
		texture_test(all);
//		all->texture->img = mlx_xpm_file_to_image(all->img->mlx, all->params->no, &all->texture->width, &all->texture->height);
		draw_map(all);
		mlx_hook(all->img->win, 2, (1L << 0), &key_hook, all);

		mlx_loop(all->img->mlx);
	}
