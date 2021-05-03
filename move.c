/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassey <fcassey@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 11:54:36 by fcassey           #+#    #+#             */
/*   Updated: 2021/05/02 11:54:37 by fcassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	press_s(t_all *all)
{
	double x;
	double y;

	x = all->map->playerx - all->map->dir_x * 2 * MOVESPEED;
	y = all->map->playery - all->map->dir_y * 2 * MOVESPEED;
	if (all->map->map[(int)x][(int)all->map->playery] != '1')
		if (all->map->map[(int)x][(int)all->map->playery] != '2')
			all->map->playerx -= all->map->dir_x * MOVESPEED;
	if (all->map->map[(int)all->map->playerx][(int)y] != '1')
		if (all->map->map[(int)all->map->playerx][(int)y] != '2')
			all->map->playery -= all->map->dir_y * MOVESPEED;
	draw_map(all);
}

void	press_w(t_all *all)
{
	double x;
	double y;

	x = all->map->playerx + all->map->dir_x * 2 * MOVESPEED;
	y = all->map->playery + all->map->dir_y * 2 * MOVESPEED;
	if (all->map->map[(int)x][(int)all->map->playery] != '1')
		if (all->map->map[(int)x][(int)all->map->playery] != '2')
			all->map->playerx += all->map->dir_x * MOVESPEED;
	if (all->map->map[(int)all->map->playerx][(int)y] != '1')
		if (all->map->map[(int)all->map->playerx][(int)y] != '2')
			all->map->playery += all->map->dir_y * MOVESPEED;
	draw_map(all);
}

void	press_right(t_all *all)
{
	double speed;
	double x;
	double px;

	speed = 0.0872665;
	x = all->map->dir_x;
	px = all->map->planex;
	all->map->dir_x = all->map->dir_x * cos(-speed) -
			all->map->dir_y * sin(-speed);
	all->map->dir_y = x * sin(-speed) + all->map->dir_y * cos(-speed);
	all->map->planex = all->map->planex * cos(-speed) -
			all->map->planey * sin(-speed);
	all->map->planey = px * sin(-speed) + all->map->planey * cos(-speed);
	draw_map(all);
}

void	press_left(t_all *all)
{
	double speed;
	double x;
	double px;

	speed = 0.0872665;
	x = all->map->dir_x;
	px = all->map->planex;
	all->map->dir_x = all->map->dir_x * cos(speed) -
			all->map->dir_y * sin(speed);
	all->map->dir_y = x * sin(speed) + all->map->dir_y * cos(speed);
	all->map->planex = all->map->planex * cos(speed) -
			all->map->planey * sin(speed);
	all->map->planey = px * sin(speed) + all->map->planey * cos(speed);
	draw_map(all);
}
