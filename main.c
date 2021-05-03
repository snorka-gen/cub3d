/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassey <fcassey@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 11:54:22 by fcassey           #+#    #+#             */
/*   Updated: 2021/05/02 11:54:24 by fcassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	get_fd(char *str)
{
	int fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		ft_check_error("where is map file?\n");
	return (fd);
}

static void	matreshka(t_all *all, int i)
{
	if (i == 0)
	{
		all->tex = malloc(sizeof(t_texture) * 5);
		if (all->tex == NULL)
			ft_check_error("Malloc Error\n");
		all->img = malloc(sizeof(t_data));
		if (all->img == NULL)
			ft_check_error("Malloc Error\n");
		all->params = ft_struct_init();
		all->map = ft_map_init();
	}
	if (i == 1)
	{
		all->zbuffer = malloc(sizeof(double) * all->params->x + 1);
		if (all->zbuffer == NULL)
			ft_check_error("Malloc Error\n");
	}
}

static int	is_it_map(char *str)
{
	int i;

	i = ft_strlen(str) - 1;
	if (str[i] == 'b' && str[i - 1] == 'u' &&
			str[i - 2] == 'c' && str[i - 3] == '.')
		return (1);
	return (0);
}

static int	save(char *str, int argc)
{
	if (argc == 3)
		if (str[0] == '-' && str[1] == '-' && str[2] == 's' && str[3] == 'a'
			&& str[4] == 'v' && str[5] == 'e' && str[6] == '\0')
			return (1);
	return (0);
}

int			main(int argc, char **argv)
{
	int			fd;
	t_all		*all;

	all = malloc(sizeof(t_all));
	matreshka(all, 0);
	if (argc == 1)
		ft_check_error("where is map?\n");
	if (is_it_map(argv[1]))
	{
		all->screen = save(argv[2], argc);
		fd = get_fd(argv[1]);
		ft_get_params(fd, all->params);
		ft_fisrtlookmap(fd, all->map);
		close(fd);
		fd = get_fd(argv[1]);
		ft_secondlookmap(fd, all->map);
		matreshka(all, 1);
		ft_create_window(all);
	}
	else
		ft_check_error("It isnt't map\n");
}
