/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassey <fcassey@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 11:54:59 by fcassey           #+#    #+#             */
/*   Updated: 2021/05/02 11:55:01 by fcassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	sprite_sort(t_sprite *sp, int x)
{
	int			i;
	int			j;
	t_sprite	temp;

	i = 0;
	while (i < x)
	{
		j = x;
		while (j  > i)
		{
			if (sp[j - 1].dis < sp[j].dis)
			{
				temp = sp[j - 1];
				sp[j - 1] = sp[j];
				sp[j] = temp;
			}
			j--;
		}
		i++;
	}
}

void	sprite_dis(t_sprite *sp, int x, float posX, float posY)
{
	int i;

	i = 0;
	while (i < x)
	{
		sp[i].dis = (posX - sp[i].x) * (posX - sp[i].x) + (posY - sp[i].y) * (posY - sp[i].y);
		i++;
	}
	sprite_sort(sp, x - 1);
}

void	get_sprite_params(t_all *all, t_drawSprite *ds, int i)
{
	ds->spriteX = all->map->sp[i].x - all->map->playerx + 0.5;
	ds->spriteY = all->map->sp[i].y - all->map->playery + 0.5;
	ds->invDet = 1.0 / (all->map->planeX * all->map->dir_y - all->map->dir_x * all->map->planeY);
	ds->transformX = ds->invDet * (all->map->dir_y * ds->spriteX - all->map->dir_x * ds->spriteY);
	ds->transformY = ds->invDet * (all->map->planeX * ds->spriteY - all->map->planeY * ds->spriteX);
	ds->spriteScreenX = (int)((all->params->x / 2) * (1 + ds->transformX / ds->transformY));
	ds->ms = (int)(0 / ds->transformY);
}

void	get_sprite_params2(t_all *all, t_drawSprite *ds)
{
//	ds->spriteHeight = abs((int)(all->params->y / ds->transformY));
	ds->spriteHeight = abs((int)((1 / ds->transformY) * all->map->dist));
	ds->drawStartY = all->params->y / 2 - ds->spriteHeight / 2 + ds->ms;
	if (ds->drawStartY < 0)
		ds->drawStartY = 0;
	ds->drawEndY = ds->spriteHeight / 2 + all->params->y / 2 + ds->ms;
	if (ds->drawEndY >= all->params->y)
		ds->drawEndY = all->params->y - 1;

//	ds->spriteWidth = abs((int)(all->params->y / ds->transformY));
	ds->spriteWidth = abs((int)((1 / ds->transformY) * all->map->dist));
	ds->drawStartX = ds->spriteScreenX - ds->spriteWidth / 2;
	if (ds->drawStartX < 0)
		ds->drawStartX = 0;
	ds->drawEndX = ds->spriteScreenX + ds->spriteWidth / 2;
	if (ds->drawEndX >= all->params->x)
		ds->drawEndX = all->params->x - 1;
}

void	get_sprite_params3(t_all *all, t_drawSprite *ds)
{
	int y;
	ds->stripe = ds->drawStartX;
	while (ds->stripe < ds->drawEndX) {
		ds->texX = (int)(256 * (ds->stripe - (-ds->spriteWidth / 2 + ds->spriteScreenX)) * all->tex[4].width /
						 ds->spriteWidth) / 256;
		if (ds->transformY > 0 && ds->stripe > 0 && ds->stripe < all->params->x && ds->transformY < all->ZBuffer[ds->stripe])
		{
			y = ds->drawStartY;
			while (y < ds->drawEndY)
			{
				ds->d = (y - ds->ms) * 256 - all->params->y * 128 + ds->spriteHeight * 128;
				ds->texY = ((ds->d * all->tex[4].height) / ds->spriteHeight) / 256;
				get_tex_color(all, ds->texX, ds->texY, 4);
				if ((all->tex[4].color & 0xFFFFFF) != 0)
					my_mlx_pixel_put(all->img, ds->stripe, y, all->tex[4].color);
				y++;
			}
		}
		ds->stripe++;
	}
}
