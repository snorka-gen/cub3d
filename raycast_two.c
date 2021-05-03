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
	if (dist->raydirx < 0)
	{
		dist->stepx = -1;
		dist->sidedistx = (all->map->playerx - dist->mapx) * dist->deltadistx;
	}
	else
	{
		dist->stepx = 1;
		dist->sidedistx = (dist->mapx + 1.0 - all->map->playerx)
				* dist->deltadistx;
	}
	if (dist->raydiry < 0)
	{
		dist->stepy = -1;
		dist->sidedisty = (all->map->playery - dist->mapy) * dist->deltadisty;
	}
	else
	{
		dist->stepy = 1;
		dist->sidedisty = (dist->mapy + 1.0 - all->map->playery)
				* dist->deltadisty;
	}
}

void	dda_distance2(t_all *all, t_dist *dist, int i)
{
	if (dist->side == 0)
	{
		dist->perpwalldist = (dist->mapx - all->map->playerx +
				(1 - dist->stepx) / 2) / dist->raydirx;
		all->tex[i].wallx = all->map->playery + dist->perpwalldist
				* dist->raydiry;
	}
	else
	{
		dist->perpwalldist = (dist->mapy - all->map->playery +
				(1 - dist->stepy) / 2) / dist->raydiry;
		all->tex[i].wallx = all->map->playerx + dist->perpwalldist
				* dist->raydirx;
	}
	all->tex[i].wallx -= floor(all->tex[i].wallx);
	all->tex[i].texx = (int)(all->tex[i].wallx * (double)all->tex[i].width);
	if (dist->side == 0 && dist->raydirx > 0)
		all->tex[i].texx = all->tex[i].width - all->tex[i].texx - 1;
	if (dist->side == 1 && dist->raydiry < 0)
		all->tex[i].texx = all->tex[i].width - all->tex[i].texx - 1;
}

int		what_side(t_dist *dist)
{
	if (dist->side == 0)
	{
		if (dist->raydirx < 0)
			return (0);
		if (dist->raydirx > 0)
			return (1);
	}
	if (dist->side == 1)
	{
		if (dist->raydiry < 0)
			return (2);
		if (dist->raydiry > 0)
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
		if (dist->sidedistx < dist->sidedisty)
		{
			dist->sidedistx += dist->deltadistx;
			dist->mapx += dist->stepx;
			dist->side = 0;
		}
		else
		{
			dist->sidedisty += dist->deltadisty;
			dist->mapy += dist->stepy;
			dist->side = 1;
		}
		if (all->map->map[dist->mapx][dist->mapy] == '1')
			hit = 1;
	}
}

void	put_the_wall(t_all *all, t_dist *dist, int x, int i)
{
	t_draw draw;

	draw.lineheight = (int)((1 / dist->perpwalldist) * all->map->dist);
	draw.drawstart = -draw.lineheight / 2 + all->params->y / 2;
	if (draw.drawstart < 0)
		draw.drawstart = 0;
	draw.drawend = draw.lineheight / 2 + all->params->y / 2;
	if (draw.drawend >= all->params->y)
		draw.drawend = all->params->y - 1;
	draw.step = 1.0 * all->tex[i].height / draw.lineheight;
	draw.texpos = (draw.drawstart - all->params->y / 2 + draw.lineheight / 2)
			* draw.step;
	while (draw.drawstart < draw.drawend)
	{
		draw.texy = (int)draw.texpos & (all->tex[i].height - 1);
		draw.texpos += draw.step;
		get_tex_color(all, all->tex[i].texx, draw.texy, i);
		my_mlx_pixel_put(all->img, x, draw.drawstart++, all->tex[i].color);
	}
}
