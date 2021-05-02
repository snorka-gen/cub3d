/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassey <fcassey@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 11:55:07 by fcassey           #+#    #+#             */
/*   Updated: 2021/05/02 11:55:08 by fcassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	get_distance_params2(t_all *all, t_dist *dist)
{
	if (dist->rayDirX < 0)
	{
		dist->stepX = -1;
		dist->sideDistX = (all->map->playerx - dist->mapX) * dist->deltaDistX;
	}
	else
	{
		dist->stepX = 1;
		dist->sideDistX = (dist->mapX + 1.0 - all->map->playerx)
				* dist->deltaDistX;
	}
	if (dist->rayDirY < 0)
	{
		dist->stepY = -1;
		dist->sideDistY = (all->map->playery - dist->mapY) * dist->deltaDistY;
	}
	else
	{
		dist->stepY = 1;
		dist->sideDistY = (dist->mapY + 1.0 - all->map->playery)
				* dist->deltaDistY;
	}
}

void	dda_distance2(t_all *all, t_dist *dist, int i, int x)
{
	if (dist->side == 0)
	{
		dist->perpWallDist = (dist->mapX - all->map->playerx +
				(1 - dist->stepX) / 2) / dist->rayDirX;
		all->tex[i].wallX = all->map->playery + dist->perpWallDist
				* dist->rayDirY;
	}
	else
	{
		dist->perpWallDist = (dist->mapY - all->map->playery +
				(1 - dist->stepY) / 2) / dist->rayDirY;
		all->tex[i].wallX = all->map->playerx + dist->perpWallDist
				* dist->rayDirX;
	}
	all->tex[i].wallX -= floor(all->tex[i].wallX);
	all->tex[i].texX = (int)(all->tex[i].wallX * (double)all->tex[i].width);
	if (dist->side == 0 && dist->rayDirX > 0)
		all->tex[i].texX = all->tex[i].width - all->tex[i].texX - 1;
	if (dist->side == 1 && dist->rayDirY < 0)
		all->tex[i].texX = all->tex[i].width - all->tex[i].texX - 1;
}

int		what_side(t_dist *dist)
{
	if (dist->side == 0)
	{
		if (dist->rayDirX < 0)
			return (0);
		if (dist->rayDirX > 0)
			return (1);
	}
	if (dist->side == 1)
	{
		if (dist->rayDirY < 0)
			return (2);
		if (dist->rayDirY > 0)
			return (3);
	}
	return (0);
}

void	dda_distance(t_all *all, t_dist *dist)
{
	int hit;

	hit = 0;
	while (hit == 0)
	{
		if (dist->sideDistX < dist->sideDistY)
		{
			dist->sideDistX += dist->deltaDistX;
			dist->mapX += dist->stepX;
			dist->side = 0;
		}
		else
		{
			dist->sideDistY += dist->deltaDistY;
			dist->mapY += dist->stepY;
			dist->side = 1;
		}
		if (all->map->map[dist->mapX][dist->mapY] == '1')
			hit = 1;
	}
}

void	put_the_wall(t_all *all, t_dist *dist, int x, int i)
{
	t_draw draw;

	draw.lineHeight = (int)((1 / dist->perpWallDist) * all->map->dist);
	draw.drawStart = -draw.lineHeight / 2 + all->params->y / 2;
	if (draw.drawStart < 0)
		draw.drawStart = 0;
	draw.drawEnd = draw.lineHeight / 2 + all->params->y / 2;
	if (draw.drawEnd >= all->params->y)
		draw.drawEnd = all->params->y - 1;
	draw.step = 1.0 * all->tex[i].height / draw.lineHeight;
	draw.texPos = (draw.drawStart - all->params->y / 2 + draw.lineHeight / 2)
			* draw.step;
	while (draw.drawStart < draw.drawEnd)
	{
		draw.texY = (int)draw.texPos & (all->tex[i].height - 1);
		draw.texPos += draw.step;
		get_tex_color(all, all->tex[i].texX, draw.texY, i);
		my_mlx_pixel_put(all->img, x, draw.drawStart++, all->tex[i].color);
	}
}
