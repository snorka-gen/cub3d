cmake_minimum_required(VERSION 3.17)
project(cub C)

set(CMAKE_C_STANDARD 99)

add_executable(cub main.c libft/ft_spacealloc.c cub.h ft_struct_init.c ft_check_error.c ft_get_params.c ft_start_parsing.c libft/ft_intstrchr.c ft_get_resolution.c ft_endofline.c ft_get_north.c ft_check_file.c ft_get_south.c ft_get_west.c ft_get_east.c ft_get_sprite.c ft_get_floor.c ft_get_ceiling.c ft_map_init.c ft_fisrtlookmap.c ft_gnl.c ft_maxlen.c ft_player_look.c ft_secondlookmap.c ft_validmap.c ft_create_window.c minilibx_opengl_20191021/mlx_get_screen_size.m raycast_one.c raycast_two.c raycast_three.c raycast_four.c move.c screenshot.c mlx_struct.c)