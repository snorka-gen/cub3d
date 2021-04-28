//
// Created by Florinda Cassey on 4/28/21.
//
#include "cub.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	texture_test(t_all *all)
{
	all->tex[0].img = mlx_xpm_file_to_image(all->img->mlx, all->params->no, &all->tex[0].width, &all->tex[0].height);
	all->tex[0].addr = mlx_get_data_addr(all->tex[0].img, &all->tex[0].bits_per_pixel, &all->tex[0].line_length,
										 &all->tex[0].endian);
	all->tex[1].img = mlx_xpm_file_to_image(all->img->mlx, all->params->so, &all->tex[1].width, &all->tex[1].height);
	all->tex[1].addr = mlx_get_data_addr(all->tex[1].img, &all->tex[1].bits_per_pixel, &all->tex[1].line_length,
										 &all->tex[1].endian);
	all->tex[2].img = mlx_xpm_file_to_image(all->img->mlx, all->params->ea, &all->tex[2].width, &all->tex[2].height);
	all->tex[2].addr = mlx_get_data_addr(all->tex[2].img, &all->tex[2].bits_per_pixel, &all->tex[2].line_length,
										 &all->tex[2].endian);
	all->tex[3].img = mlx_xpm_file_to_image(all->img->mlx, all->params->we, &all->tex[3].width, &all->tex[3].height);
	all->tex[3].addr = mlx_get_data_addr(all->tex[3].img, &all->tex[3].bits_per_pixel, &all->tex[3].line_length,
										 &all->tex[3].endian);
	all->tex[4].img = mlx_xpm_file_to_image(all->img->mlx, all->params->s, &all->tex[4].width, &all->tex[4].height);
	all->tex[4].addr = mlx_get_data_addr(all->tex[4].img, &all->tex[4].bits_per_pixel, &all->tex[4].line_length,
										 &all->tex[4].endian);
}

void	get_tex_color(t_all *all, int x, int y, int i)
{
char *dst;
dst = all->tex[i].addr + (y * all->tex[i].line_length + x * (all->tex[i].bits_per_pixel/8));
all->tex[i].color = *(unsigned int *)dst;
}

void	get_distance_params(t_all *all, t_dist *dist, int i)
{
	dist->cameraX = 2 * i / (double)all->params->x - 1;
	dist->rayDirX = all->map->dir_x + all->map->planeX * dist->cameraX;
	dist->rayDirY = all->map->dir_y + all->map->planeY * dist->cameraX;
	if (dist->rayDirY == 0)
		dist->deltaDistX = 0;
	else if (dist->rayDirX == 0)
		dist->deltaDistX = 1;
	else
		dist->deltaDistX= fabs(1/dist->rayDirX);
	if (dist->rayDirX == 0)
		dist->deltaDistY = 0;
	else if (dist->rayDirY == 0)
		dist->deltaDistY = 1;
	else dist->deltaDistY = fabs(1/dist->rayDirY);
}
