/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassey <fcassey@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 11:55:17 by fcassey           #+#    #+#             */
/*   Updated: 2021/05/02 11:55:18 by fcassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	header_to_bmp(int fd, t_all *all, int size)
{
	char	header[54];
	int		i;

	ft_bzero(header, 54);
	header[0] = 0x42;
	header[1] = 0x4D;
	ft_memcpy(&header[2], &size, 4);
	header[10] = 0x36;
	header[14] = 0x28;
	ft_memcpy(&header[18], &all->params->x, 4);
	i = -all->params->y;
	ft_memcpy(&header[22], &i, 4);
	header[26] = 0x01;
	header[28] = 0x20;
	write(fd, header, 54);
}

static void	draw_screenshot(t_all *all)
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
		dda_distance2(all, dist, x, i);
		all->ZBuffer[i] = dist->perpWallDist;
		put_the_wall(all, dist, i, x);
		i++;
	}
	free(dist);
	put_sprites(all);
}

void		screenshot(t_all *all)
{
	int fd;
	int size;

	fd = open("screenshot.bmp", O_CREAT | O_RDWR, 0666);
	draw_screenshot(all);
	size = all->params->x * all->params->y * 4;
	header_to_bmp(fd, all, size);
	write(fd, all->img->addr, size);
	close(fd);
	exit(0);
}
