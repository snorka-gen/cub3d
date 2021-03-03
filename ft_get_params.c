//
// Created by Аида Сайдашева on 08.02.2021.
//

#include "cub.h"

static int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

static void		create_color(t_struct *params)
{
	params->up = create_trgb(0, params->sky[0], params->sky[1], params->sky[2]);
	params->down = create_trgb(0, params->floor[0], params->floor[1], params->floor[2]);
}

void ft_get_params(int fd, t_struct *params)
{
	char *line;
	int i;
	int gnl;

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
			ft_check_error(6);
		free(line);
	}
	create_color(params);
//	printf("Resolution %d %d\n", params->x, params->y);
//	printf("no %s\n", params->no);
//	printf("so %s\n", params->so);
//	printf("ea %s\n", params->ea);
//	printf("we %s\n", params->we);
//	printf("s %s\n", params->s);
//	printf("floor %d %d %d\n", params->floor[0], params->floor[1], params->floor[2]);
//	printf("floor %d %d %d\n", params->sky[0], params->sky[1], params->sky[2]);

}