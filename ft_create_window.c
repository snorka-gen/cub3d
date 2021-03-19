//
// Created by Аида Сайдашева on 02.03.2021.
//
#include "cub.h"
#include <math.h>

//
typedef struct	s_plr //структура для игрока и луча
{
	float		x;
	float		y;
	float		dir;
	float		start;
	float		end;
}				  t_plr;

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

static void draw_map(t_all *all) {
	int x;
	int y;
	t_plr	ray; // задаем координаты луча равные координатам игрока

	x = 0;
	// Отрисовка карты с положением игрока
	while (all->map->map[x]) {
		y = 0;
		while (all->map->map[x][y]) {
			if (all->map->map[x][y] == '1')
				put_pixels(all->img, y * 10, x * 10, 0xffffff);
			if (all->map->map[x][y] == '2')
				put_pixels(all->img, y * 10, x * 10, 0xff0000);
			if (all->map->map[x][y] == 'E' || all->map->map[x][y] == 'N' || all->map->map[x][y] == 'W' ||
				all->map->map[x][y] == 'S')
				put_pixels(all->img, y * 10, x * 10, all->params->down);
			if (all->map->map[x][y] == '0')
				put_pixels(all->img, y * 10, x * 10, all->params->down);
			put_pixels(all->img, all->map->playery, all->map->playerx, 0x0000ff);
			y++;
		}
		x++;
	}
	ray.x = all->map->playerx;
	ray.y = all->map->playery;
//	printf("%f\n%f\n", ray.x, ray.y);
//	printf("%c\n", all->map->map[(int)(ray.x / 10)][(int)(ray.y / 10)]);

// Отрисовка луча "взгляда"
	ray.dir = 3.14;
	float c = 0;
	while (all->map->map[(int)(ray.x / 10)][(int)(ray.y / 10)] != '1')
	{
		ray.x += c * cos(ray.dir);
		ray.y += c * sin(ray.dir);
		c += 0.05;
		my_mlx_pixel_put(all->img, ray.y, ray.x, 0x990099);
	}
	mlx_put_image_to_window(all->img->mlx, all->img->win, all->img->img, 0, 0);
}

	int key_hook(int key, t_all *all) {
//	printf("%d\n", all->map->playerx);
		mlx_clear_window(all->img->mlx, all->img->win);
//	all->map->playerx -= 1;
//	printf("ddd\n");
		if (key == 13) {
			all->map->playerx -= 1;
		}
		if (key == 53) {
			mlx_destroy_window(all->img->mlx, all->img->win);
			exit(0);
		}
//	printf("%d\n", all->map->playerx);
		draw_map(all);
		return (0);
	}

	void ft_create_window(t_all *all)
	{
//	t_data  *img;

		all->img = malloc(sizeof(t_data));
		all->img->mlx = mlx_init();
		all->img->win = mlx_new_window(all->img->mlx, all->params->x, all->params->y, "test");
//	draw_map(&win, map, params);
//	mlx_key_hook(win.win, key_hook, &win);
//	mlx_loop(win.mlx);
		all->img->img = mlx_new_image(all->img->mlx, all->params->x, all->params->y);
		all->img->addr = mlx_get_data_addr(all->img->img, &all->img->bits_per_pixel, &all->img->line_length,
										   &all->img->endian);
		draw_map(all);
//	printf("%d\n", all->map->playerx);
//	printf("%d\n", all->map->playery);

//	draw_map(all);
		mlx_hook(all->img->win, 2, (1L << 0), &key_hook, all);
		mlx_loop(all->img->mlx);
	}
