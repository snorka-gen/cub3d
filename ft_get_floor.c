/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_floor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassey <fcassey@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 11:52:22 by fcassey           #+#    #+#             */
/*   Updated: 2021/05/02 11:52:24 by fcassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	ft_get_r(char *line, t_struct *params, int i)
{
	while (line[i] == ' ' && line[i])
		i++;
	if (ft_strchr("0123456789", line[i]))
		while (ft_isdigit(line[i]))
		{
			params->floor[0] = params->floor[0] * 10 + (line[i] - 48);
			if (params->floor[0] > 255)
				ft_check_error("Floor color is wrong\n");
			i++;
		}
	else
		ft_check_error("Floor color is wrong\n");
	return (i);
}

static int	ft_get_g(char *line, t_struct *params, int i)
{
	while (line[i] == ' ' && line[i])
		i++;
	if (line[i] == ',')
		i++;
	while (line[i] == ' ' && line[i])
		i++;
	if (ft_strchr("0123456789", line[i]))
		while (ft_isdigit(line[i]))
		{
			params->floor[1] = params->floor[1] * 10 + (line[i] - 48);
			if (params->floor[1] > 255)
				ft_check_error("Floor color is wrong\n");
			i++;
		}
	else
		ft_check_error("Floor color is wrong\n");
	return (i);
}

static int	ft_get_b(char *line, t_struct *params, int i)
{
	while (line[i] == ' ' && line[i])
		i++;
	if (line[i] == ',')
		i++;
	while (line[i] == ' ' && line[i])
		i++;
	if (ft_strchr("0123456789", line[i]))
		while (ft_isdigit(line[i]))
		{
			params->floor[2] = params->floor[2] * 10 + (line[i] - 48);
			if (params->floor[2] > 255)
				ft_check_error("Floor color is wrong\n");
			i++;
		}
	else
		ft_check_error("Floor color is wrong\n");
	return (i);
}

void		ft_get_floor(char *line, t_struct *params, int i)
{
	if (params->floor[0] != -1)
		ft_check_error("Too much color...\n");
	params->floor[0] = 0;
	params->floor[1] = 0;
	params->floor[2] = 0;
	i = ft_get_r(line, params, i);
	i = ft_get_g(line, params, i);
	i = ft_get_b(line, params, i);
	ft_endofline(line, i);
	params->flag += 1;
}
