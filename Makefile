NAME = cub3D

FLAG = -Wall -Wextra -Werror

MLX = -framework OpenGL -framework Appkit -O2

SRC = ft_check_error.c ft_check_file.c ft_create_window.c\
			ft_endofline.c ft_fisrtlookmap.c ft_get_ceiling.c\
			ft_get_east.c ft_get_floor.c ft_get_north.c\
			ft_get_params.c ft_get_resolution.c ft_get_south.c\
			ft_get_sprite.c ft_get_west.c ft_gnl.c ft_map_init.c\
			ft_maxlen.c ft_player_look.c ft_secondlookmap.c\
			ft_start_parsing.c ft_struct_init.c ft_validmap.c\
			main.c mlx_struct.c move.c raycast_four.c\
			raycast_one.c raycast_two.c raycast_three.c\
			screenshot.c some_sprite_things.c

all:	${NAME}

${NAME}:
		make -C ./libft/
		cp ./libft/libft.a .
		make -C ./get_next_line/
		cp ./get_next_line/get_next_line.a .
		make -C ./minilibx_opengl_20191021/
		cp ./minilibx_opengl_20191021/libmlx.a .
		gcc ${FLAG} ${SRC} -o ${NAME} -L. -I. libft.a get_next_line.a libmlx.a ${MLX}

clean:
		rm -f ./libft/*.o
		rm -f ./get_next_line/*.o
		rm -f ./minilibx_opengl_20191021/*.o

fclean:	clean
		rm -f libft.a
		rm -f get_next_line.a
		rm -f libmlx.a
		rm -f ${NAME}

re:		fclean all

.PHONY: re all clean fclean cub3D
