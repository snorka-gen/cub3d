//
// Created by Аида Сайдашева on 08.02.2021.
//

#ifndef CUB_H
# define CUB_H

#include <stdio.h>
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include "minilibx_opengl_20191021/mlx.h"

typedef struct s_struct
{
	int		x;
	int		y;
	int		flag;
	int		*floor;
	int		*sky;
	char	*no;
	char	*ea;
	char	*we;
	char	*so;
	char	*s;
	int 	up;
	int 	down;
}				t_struct;

typedef struct s_map
{
	int		len;
	int 	count;
	int		player;
	int		playerx;
	int		playery;
	char	**map;
}				t_map;

typedef struct	s_data
{
	void	*img;
	void	*mlx;
	void	*win;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_all
{
	t_data		img;
	t_map		map;
	t_struct	params;
}				t_all;


t_struct		*ft_struct_init();
void			ft_check_error(int i);
void			ft_get_params(int fd, t_struct *params);
void			ft_start_parsing(char *line, t_struct *params, int i);
void			ft_get_resolution(char *line, t_struct *params, int i);
void			ft_endofline(char *line, int i);
void			ft_get_north(char *line, t_struct *params, int i);
void			ft_get_south(char *line, t_struct *params, int i);
void			ft_check_file(char *path);
void			ft_get_west(char *line, t_struct *params, int i);
void			ft_get_east(char *line, t_struct *params, int i);
void			ft_get_sprite(char *line, t_struct *params, int i);
void			ft_get_floor(char *line, t_struct *params, int i);
void			ft_get_ceiling(char *line, t_struct *params, int i);
t_map			*ft_map_init();
void			ft_fisrtlookmap(int fd, t_map *map);
char			*ft_gnl_par(int fd);
char 			*ft_gnl(int fd, t_map *map);
void			ft_maxlen(t_map *map, int len);
void			ft_player_look(t_map *map, char *line);
void			ft_secondlookmap(int fd, t_map *map);
void			ft_validmap(t_map *map);
void			ft_create_window(t_map *map, t_struct *params);
int				key_hook(int key, t_data *img);
#endif
