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
		while (j > i)
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

void	sprite_dis(t_sprite *sp, int x, float posx, float posy)
{
	int i;

	i = 0;
	while (i < x)
	{
		sp[i].dis = (posx - sp[i].x) * (posx - sp[i].x) +
				(posy - sp[i].y) * (posy - sp[i].y);
		i++;
	}
	sprite_sort(sp, x - 1);
}

void	get_sprite_params(t_all *all, t_drawsprite *ds, int i)
{
	ds->spritex = all->map->sp[i].x - all->map->playerx + 0.5;
	ds->spritey = all->map->sp[i].y - all->map->playery + 0.5;
	ds->invdet = 1.0 / (all->map->planex * all->map->dir_y -
			all->map->dir_x * all->map->planey);
	ds->transformx = ds->invdet * (all->map->dir_y * ds->spritex -
			all->map->dir_x * ds->spritey);
	ds->transformy = ds->invdet * (all->map->planex * ds->spritey -
			all->map->planey * ds->spritex);
	ds->spritescreenx = (int)((all->params->x / 2) * (1 + ds->transformx
			/ ds->transformy));
	ds->ms = (int)(0 / ds->transformy);
}

void	get_sprite_params2(t_all *all, t_drawsprite *ds)
{
	ds->spriteheight = abs((int)((1 / ds->transformy) * all->map->dist));
	ds->drawstarty = all->params->y / 2 - ds->spriteheight / 2 + ds->ms;
	if (ds->drawstarty < 0)
		ds->drawstarty = 0;
	ds->drawendy = ds->spriteheight / 2 + all->params->y / 2 + ds->ms;
	if (ds->drawendy >= all->params->y)
		ds->drawendy = all->params->y - 1;
	ds->spritewidth = abs((int)((1 / ds->transformy) * all->map->dist));
	ds->drawstartx = ds->spritescreenx - ds->spritewidth / 2;
	if (ds->drawstartx < 0)
		ds->drawstartx = 0;
	ds->drawendx = ds->spritescreenx + ds->spritewidth / 2;
	if (ds->drawendx >= all->params->x)
		ds->drawendx = all->params->x - 1;
}

void	get_sprite_params3(t_all *all, t_drawsprite *ds)
{
	int y;

	ds->stripe = ds->drawstartx;
	while (ds->stripe < ds->drawendx)
	{
		sprite_texx(all, ds);
		if (ds->transformy > 0 && ds->stripe > 0 && ds->stripe <
			all->params->x && ds->transformy < all->zbuffer[ds->stripe])
		{
			y = ds->drawstarty;
			while (y < ds->drawendy)
			{
				ds->d = (y - ds->ms) * 256 - all->params->y * 128 +
						ds->spriteheight * 128;
				ds->texy = ((ds->d * all->tex[4].height) /
						ds->spriteheight) / 256;
				get_tex_color(all, ds->texx, ds->texy, 4);
				if ((all->tex[4].color & 0xFFFFFF) != 0)
					my_mlx_pixel_put(all->img, ds->stripe, y,
					all->tex[4].color);
				y++;
			}
		}
		ds->stripe++;
	}
}
