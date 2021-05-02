/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassey <fcassey@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 11:51:45 by fcassey           #+#    #+#             */
/*   Updated: 2021/05/02 11:51:46 by fcassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	press_d(t_all *all)
{
	double	x;
	double	y;

	x = all->map->playerx + all->map->dir_y * 2 * MOVESPEED;
	y = all->map->playery - all->map->dir_x * 2 * MOVESPEED;
	if (all->map->map[(int)x][(int)all->map->playery] != '1')
		if (all->map->map[(int)x][(int)all->map->playery] != '2')
			all->map->playerx += all->map->dir_y * MOVESPEED;
	if (all->map->map[(int)all->map->playerx][(int)y] != '1')
		if (all->map->map[(int)all->map->playerx][(int)y] != '2')
			all->map->playery -= all->map->dir_x * MOVESPEED;
	draw_map(all);
}

void	press_a(t_all *all)
{
	double x;
	double y;

	x = all->map->playerx - all->map->dir_y * 2 * MOVESPEED;
	y = all->map->playery + all->map->dir_x * 2 * MOVESPEED;
	if (all->map->map[(int)x][(int)all->map->playery] != '1')
		if (all->map->map[(int)x][(int)all->map->playery] != '2')
			all->map->playerx -= all->map->dir_y * MOVESPEED;
	if (all->map->map[(int)all->map->playerx][(int)y] != '1')
		if (all->map->map[(int)all->map->playerx][(int)y] != '2')
			all->map->playery += all->map->dir_x * MOVESPEED;
	draw_map(all);
}

int		key_hook(int key, t_all *all)
{
	if (key == 13)
		press_w(all);
	if (key == 1)
		press_s(all);
	if (key == 124)
		press_right(all);
	if (key == 123)
		press_left(all);
	if (key == 2)
		press_d(all);
	if (key == 0)
		press_a(all);
	if (key == 53)
	{
		mlx_destroy_window(all->img->mlx, all->img->win);
		exit(0);
	}
	return (0);
}

int		cub_end(t_all *all)
{
	mlx_destroy_window(all->img->mlx, all->img->win);
	exit(0);
	return (0);
}

void	ft_create_window(t_all *all)
{
	mlx_struct(all->img, all->params->x, all->params->y);
	texture_test(all);
	all->map->dist = (all->params->x / 2) / tan(0.575959);
	if (all->screen == 1)
		screenshot(all);
	draw_map(all);
	mlx_hook(all->img->win, 2, (1L << 0), &key_hook, all);
	mlx_hook(all->img->win, 17, 1L << 17, &cub_end, all);
	mlx_loop(all->img->mlx);
}
