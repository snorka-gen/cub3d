//
// Created by Аида Сайдашева on 02.03.2021.
//
#include "cub.h"

int		key_hook(int key, t_data *img)
{
	printf("%d\n", key);
//	if (key == 13)
//
	if (key == 53)
	{
		mlx_destroy_window(img->mlx, img->win);
		exit(0);
	}
	draw
	return (0);
}



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

static void draw_map(t_data *img, t_map *map, t_struct *params)
{
	int x;
	int y;

	x = 0;
	while (map->map[x])
	{
		y = 0;
		while (map->map[x][y]
		{
			if (map->map[x][y] == '1')
				put_pixels(img, y * 10, x * 10, 0xffffff);
			if (map->map[x][y] == '2')
				put_pixels(img, y * 10, x * 10, 0xff0000);
			if (map->map[x][y] == 'E' || map->map[x][y] == 'N' || map->map[x][y] == 'W' || map->map[x][y] == 'S')
				put_pixels(img, y * 10, x * 10, params->down);
			if (map->map[x][y] == '0')
				put_pixels(img, y * 10, x * 10, params->down);
			put_pixels(img, map->playery * 10, map->playerx * 10, 0x0000ff);
			y++;
		}
		x++;
	}
}

void	ft_create_window(t_map *map, t_struct *params)
{
	t_data  img;

	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, params->x, params->y, "test");
//	draw_map(&win, map, params);
//	mlx_key_hook(win.win, key_hook, &win);
//	mlx_loop(win.mlx);
	img.img = mlx_new_image(img.mlx, params->x, params->y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
	draw_map(&img, map, params);
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_hook(img.win, 2, (1L<<2), key_hook, &img);
	mlx_loop(img.mlx);
}

