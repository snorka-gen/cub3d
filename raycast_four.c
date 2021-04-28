//
// Created by Florinda Cassey on 4/28/21.
//

#include "cub.h"

void	put_sprites(t_all *all)
{
	t_drawSprite ds;

	sprite_dis(all->map->sp, all->map->sprite, all->map->playerx, all->map->playery);
	int i = 0;
	while (i < all->map->sprite) {
		get_sprite_params(all, &ds, i);
		get_sprite_params2(all, &ds);
		get_sprite_params3(all, &ds);
		i++;
	}
}
void	put_floor(t_all *all)
{
	int x;
	int y;

	y = 0;
	while (y < all->params->y/2)
	{
		x = 0;
		while (x < all->params->x)
			my_mlx_pixel_put(all->img, x++, y, all->params->up);
		y++;
	}
	while (y < all->params->y)
	{
		x = 0;
		while (x < all->params->x)
		{
			my_mlx_pixel_put(all->img, x, y, all->params->down);
			x++;
		}
		y++;
	}
}

void	draw_map(t_all *all)
{
	t_dist dist;
	int i;
	int x;

	i = 0;
	put_floor(all);
	while (i < all->params->x)
	{
		get_distance_params(all, &dist, i);
		get_distance_params2(all, &dist);
		dda_distance(all, &dist);
		x = what_side(all, &dist);
		dda_distance2(all, &dist, x, i);
		all->ZBuffer[i] = dist.perpWallDist;
		put_the_wall(all, &dist, i, x);
		i++;
	}
	put_sprites(all);
	mlx_put_image_to_window(all->img->mlx, all->img->win, all->img->img, 0, 0);
}