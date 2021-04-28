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
#include <math.h>
#define SCALE 64
#define PI 3.1415926
#define MOVESPEED 0.2
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
typedef struct s_sprite
{
	float x;
	float y;
	float dis;
}				t_sprite;
typedef struct s_map
{
	int		len;
	int 	count;
	int		player;
	float		playerx;
	float		playery;
	float planeX;
	float planeY;
	float dir_x;
	float dir_y;
	int sprite;
	t_sprite *sp;
	char	**map;
	int 	side;
	float	rad;
	float dist;
}				t_map;

typedef struct s_dist
{
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	double	deltaDistX;
	double	deltaDistY;
	double	sideDistX;
	double	sideDistY;
	double	perpWallDist;
	int		stepX;
	int		stepY;
	int 	side;
	int 	mapX;
	int 	mapY;
}				t_dist;

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


typedef struct	s_plr //структура для игрока и луча
{
	float planeX;
	float planeY;
	float dir_x;
	float dir_y;
}				  t_plr;

typedef struct s_texture
{
	void *img;
	int width;
	int height;
	double wallX;
	char        *addr;
	int         bits_per_pixel;
	int         line_length;
	int         endian;
	int		color;
	int texX;

}				t_texture;

typedef struct s_draw
{
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	double	step;
	double	texPos;
	int		texY;
}				t_draw;

typedef struct s_drawSprite
{
	double spriteX;
	double spriteY;
	double invDet;
	double transformX;
	double transformY;
	int spriteScreenX;
	int spriteHeight;
	int drawStartY;
	int drawEndY;
	int stripe;
	int spriteWidth;
	int drawStartX;
	int drawEndX;
	int texY;
	int texX;
	int d;
	int y;
}			t_drawSprite;

typedef struct s_all
{
	t_data		*img;
	t_map		*map;
	t_struct	*params;
	t_plr		*ray;
	t_plr		*plr;
	t_texture 	*tex;
	float		*ZBuffer;
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
void			ft_create_window(t_all *all);
int				key_hook(int key, t_all *all);
double			radian(double degree);
#endif
