/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: {author_and_email}                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 17:04:00 by aidasajdaseva     #+#    #+#             */
/*   Updated: 2021/03/03 15:59:43 by aidasajdaseva    ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"




int main(int argc, char **argv)
{
	(void)		argc;
	int			fd;
	t_all		*all;
	t_texture texture;

	all = malloc(sizeof (t_all));
	all->texture = &texture;
	all->img = malloc(sizeof(t_data));
	all->ray = malloc(sizeof (t_plr));
	fd = open(argv[1], O_RDONLY);
	all->params = ft_struct_init();
	all->map = ft_map_init();
	ft_get_params(fd, all->params);
	ft_fisrtlookmap(fd, all->map);
	close (fd);
	fd = open(argv[1], O_RDONLY);
	ft_secondlookmap(fd, all->map);
	ft_create_window(all);
}
