/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassey <fcassey@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 11:54:45 by fcassey           #+#    #+#             */
/*   Updated: 2021/05/02 11:54:46 by fcassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	put_sprites(t_all *all)
{
	t_drawsprite	ds;
	int				i;

	i = 0;
	sprite_dis(all->map->sp, all->map->sprite, all->map->playerx,
			all->map->playery);
	while (i < all->map->sprite)
	{
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
	while (y < all->params->y / 2)
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
	t_dist	*dist;
	int		i;
	int		x;

	i = 0;
	dist = malloc(sizeof(t_dist));
	if (dist == NULL)
		ft_check_error("MALLOC ERROR\n");
	put_floor(all);
	while (i < all->params->x)
	{
		get_distance_params(all, dist, i);
		get_distance_params2(all, dist);
		dda_distance(all, dist);
		x = what_side(dist);
		dda_distance2(all, dist, x);
		all->zbuffer[i] = dist->perpwalldist;
		put_the_wall(all, dist, i, x);
		i++;
	}
	free(dist);
	put_sprites(all);
	mlx_put_image_to_window(all->img->mlx, all->img->win, all->img->img, 0, 0);
}
