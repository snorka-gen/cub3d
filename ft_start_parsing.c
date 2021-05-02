/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassey <fcassey@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 11:53:57 by fcassey           #+#    #+#             */
/*   Updated: 2021/05/02 11:53:59 by fcassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	pars1(char *line, t_struct *params, int i)
{
	if (line[i] == 'N' && line[i + 1] == 'O' &&
		(line[i + 2] == ' ' || line[i + 2] == '.'))
		ft_get_north(line, params, i + 2);
	if (line[i] == 'S' && line[i + 1] == 'O' &&
		(line[i + 2] == ' ' || line[i + 2] == '.'))
		ft_get_south(line, params, i + 2);
	if (line[i] == 'W' && line[i + 1] == 'E' &&
		(line[i + 2] == ' ' || line[i + 2] == '.'))
		ft_get_west(line, params, i + 2);
	if (line[i] == 'E' && line[i + 1] == 'A' &&
		(line[i + 2] == ' ' || line[i + 2] == '.'))
		ft_get_east(line, params, i + 2);
}

void		ft_start_parsing(char *line, t_struct *params, int i)
{
	if (line[i] == 'R' && (line[i + 1] == ' ' || ft_isalnum(line[i + 1])))
		ft_get_resolution(line, params, i + 2);
	pars1(line, params, i);
	if (line[i] == 'S' && (line[i + 1] == ' ' || line[i + 1] == '.'))
		ft_get_sprite(line, params, i + 1);
	if (line[i] == 'F' && (line[i + 1] == ' ' || ft_isalnum(line[i + 1])))
		ft_get_floor(line, params, i + 2);
	if (line[i] == 'C' && (line[i + 1] == ' ' || ft_isalnum(line[i + 1])))
		ft_get_ceiling(line, params, i + 2);
}
