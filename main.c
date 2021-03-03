/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: {author_and_email}                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 17:04:00 by aidasajdaseva     #+#    #+#             */
/*   Updated: 2021/03/02 23:07:47 by aidasajdaseva    ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"



int main(int argc, char **argv)
{
	(void)		argc;
	int			fd;
	t_struct	*params;
	t_map		*map;

	fd = open(argv[1], O_RDONLY);
	params = ft_struct_init();
	map = ft_map_init();
	ft_get_params(fd, params);
	ft_fisrtlookmap(fd, map);
	close (fd);
	fd = open(argv[1], O_RDONLY);
	ft_secondlookmap(fd, map);
	ft_create_window(map, params);
}
