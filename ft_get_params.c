/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassey <fcassey@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 11:52:39 by fcassey           #+#    #+#             */
/*   Updated: 2021/05/02 11:52:40 by fcassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static void	create_color(t_struct *params)
{
	params->up = create_trgb(0, params->sky[0],
							params->sky[1], params->sky[2]);
	params->down = create_trgb(0, params->floor[0],
							params->floor[1], params->floor[2]);
}

void		ft_get_params(int fd, t_struct *params)
{
	char	*line;
	int		i;

	params->flag = 0;
	while (params->flag != 9)
	{
		i = 0;
		line = ft_gnl_par(fd);
		while (line[i] && line[i] == ' ')
			i++;
		if (ft_intstrchr("RNSWEFC", line[i]) != -1 && line[i])
			ft_start_parsing(line, params, i);
		else if (line[i] != '\0')
			ft_check_error("Check params!\n");
		free(line);
	}
	create_color(params);
}
