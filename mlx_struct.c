/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassey <fcassey@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 11:54:29 by fcassey           #+#    #+#             */
/*   Updated: 2021/05/02 11:54:30 by fcassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	mlx_struct(t_data *img, int x, int y)
{
	img->mlx = mlx_init();
	if (img->mlx == NULL)
		ft_check_error("Malloc Error\n");
	img->win = mlx_new_window(img->mlx, x, y, "cub3D");
	if (img->win == NULL)
		ft_check_error("Malloc Error\n");
	img->img = mlx_new_image(img->mlx, x, y);
	if (img->img == NULL)
		ft_check_error("Malloc Error\n");
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
					&img->line_length, &img->endian);
	if (img->addr == NULL)
		ft_check_error("Malloc Error\n");
}
