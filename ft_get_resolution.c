/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_resolution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassey <fcassey@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 11:52:45 by fcassey           #+#    #+#             */
/*   Updated: 2021/05/02 11:52:46 by fcassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	ft_get_x(char *line, t_struct *params, int i, int width)
{
	while (line[i] == ' ' && line[i])
		i++;
	if (ft_strchr("123456789", line[i]))
		while (ft_isdigit(line[i]))
		{
			params->x = params->x * 10 + (line[i] - 48);
			if (params->x > width)
				params->x = width;
			i++;
		}
	else
		ft_check_error("Something wrong with resolution\n");
	return (i);
}

static int	ft_get_y(char *line, t_struct *params, int i, int height)
{
	while (line[i] == ' ' && line[i])
		i++;
	if (ft_strchr("123456789", line[i]))
		while (ft_isdigit(line[i]))
		{
			params->y = params->y * 10 + (line[i] - 48);
			if (params->y > height)
				params->y = height;
			i++;
		}
	else
		ft_check_error("Something wrong with resolution\n");
	return (i);
}

void		ft_get_resolution(char *line, t_struct *params, int i)
{
	int width;
	int height;

	mlx_get_screen_size(&width, &height);
	if (params->x != 0)
		ft_check_error("Too much resolution...\n");
	i = ft_get_x(line, params, i, width);
	i = ft_get_y(line, params, i, height);
	ft_endofline(line, i);
	params->flag += 2;
}
