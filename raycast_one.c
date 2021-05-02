/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassey <fcassey@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 11:54:51 by fcassey           #+#    #+#             */
/*   Updated: 2021/05/02 11:54:52 by fcassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	texture_test(t_all *all)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		all->tex[i].img = mlx_xpm_file_to_image(all->img->mlx,
				all->params->tex[i], &all->tex[i].width, &all->tex[i].height);
		all->tex[i].addr = mlx_get_data_addr(all->tex[i].img,
				&all->tex[i].bpp, &all->tex[i].line_length, &all->tex[i].end);
		i++;
	}
}

void	get_tex_color(t_all *all, int x, int y, int i)
{
	char	*dst;

	dst = all->tex[i].addr + (y * all->tex[i].line_length + x
			* (all->tex[i].bpp / 8));
	if (dst == NULL)
		ft_check_error("COLOR ERRRRRROR\n");
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
		dist->deltaDistX = fabs(1 / dist->rayDirX);
	if (dist->rayDirX == 0)
		dist->deltaDistY = 0;
	else if (dist->rayDirY == 0)
		dist->deltaDistY = 1;
	else
		dist->deltaDistY = fabs(1 / dist->rayDirY);
	dist->mapX = (int)all->map->playerx;
	dist->mapY = (int)all->map->playery;
}
