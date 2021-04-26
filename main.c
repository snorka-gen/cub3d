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
	t_plr plr;
	t_plr ray;

	all = malloc(sizeof (t_all));
	all->tex = &texture;
	all->plr = &plr;
	all->ray = &ray;
	all->img = malloc(sizeof(t_data));
	all->ray = malloc(sizeof (t_plr));
	fd = open(argv[1], O_RDONLY);
	all->params = ft_struct_init();
	all->map = ft_map_init();
	ft_get_params(fd, all->params);
	ft_fisrtlookmap(fd, all->map);
	close (fd);
//	double test = 10053/64;
//	double test2 = floor(test);
//	printf("double %lf\nint %d\nfloor %lf\nint floor %d\n", test, (int)(test), floor(test), (int)floor(test));
//	double x[2];
//	modf(63/64, x);
//	printf("%d, %f\n", (int)x[0],x[1]);
	fd = open(argv[1], O_RDONLY);
	ft_secondlookmap(fd, all->map);
	ft_create_window(all);


}
