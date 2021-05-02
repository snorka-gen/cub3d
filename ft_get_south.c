/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_south.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassey <fcassey@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 11:52:51 by fcassey           #+#    #+#             */
/*   Updated: 2021/05/02 11:52:53 by fcassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_get_south(char *line, t_struct *params, int i)
{
	int	start;

	if (params->tex[1] != NULL)
		ft_check_error("Too much textures....\n");
	while (line[i] == ' ' && line[i])
		i++;
	start = i;
	while (line[i])
		i++;
	i -= 1;
	while (line[i] == ' ')
		i--;
	if (line[i] != 'm' || line[i - 1] != 'p' ||
			line[i - 2] != 'x' || line[i - 3] != '.')
		ft_check_error("it isn't XPM file! Please add XPM texture\n");
	if (!(params->tex[1] = ft_substr((const char *)line, start, i - start + 1)))
		ft_check_error("Malloc Error\n");
	ft_check_file(params->tex[1]);
	params->flag += 1;
}
