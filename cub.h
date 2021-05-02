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
	char 	**tex;
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

typedef struct s_texture
{
	void			*img;
	int				width;
	int				height;
	double			wallX;
	char			*addr;
	int				bpp;
	int				line_length;
	int				end;
	unsigned int	color;
	int				texX;

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
	int ms;
}			t_drawSprite;

typedef struct s_all
{
	t_data		*img;
	t_map		*map;
	t_struct	*params;
	t_texture 	*tex;
	float		*ZBuffer;
	int 		screen;
}				t_all;


t_struct		*ft_struct_init(void);
void			ft_check_error(char *str);
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
t_map			*ft_map_init(void);
void			ft_fisrtlookmap(int fd, t_map *map);
char			*ft_gnl_par(int fd);
char 			*ft_gnl(int fd, t_map *map);
void			ft_maxlen(t_map *map, int len);
void			ft_player_look(t_map *map, char *line);
void			ft_secondlookmap(int fd, t_map *map);
void			ft_validmap(t_map *map);
void			ft_create_window(t_all *all);
int				key_hook(int key, t_all *all);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			texture_test(t_all *all);
void			get_tex_color(t_all *all, int x, int y, int i);
void			get_distance_params(t_all *all, t_dist *dist, int i);
void			get_distance_params2(t_all *all, t_dist *dist);
void			dda_distance2(t_all *all, t_dist *dist, int i, int x);
int				what_side(t_dist *dist);
void			dda_distance(t_all *all, t_dist *dist);
void			put_the_wall(t_all *all, t_dist *dist, int x, int i);
void			sprite_sort(t_sprite *sp, int x);
void			sprite_dis(t_sprite *sp, int x, float posX, float posY);
void			get_sprite_params(t_all *all, t_drawSprite *ds, int i);
void			get_sprite_params2(t_all *all, t_drawSprite *ds);
void			get_sprite_params3(t_all *all, t_drawSprite *ds);
void			put_sprites(t_all *all);
void			put_floor(t_all *all);
void			draw_map(t_all *all);
void			press_s(t_all *all);
void			press_w(t_all *all);
void			press_right(t_all *all);
void			press_left(t_all *all);
int				key_hook(int key, t_all *all);
void			press_a(t_all *all);
void			press_d(t_all *all);
void			screenshot(t_all *all);
void			mlx_struct(t_data *img, int x, int y);


#endif
