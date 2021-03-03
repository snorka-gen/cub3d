NAME = test.out

all:	${NAME}

${NAME}:
		make -C ./libft/
		cp ./libft/libft.a .
		make -C ./get_next_line/
		cp ./get_next_line/get_next_line.a .
		make -C ./minilibx_opengl_20191021/
		cp ./minilibx_opengl_20191021/libmlx.a .
		gcc *.c -o ${NAME} -L. -I. libft.a get_next_line.a libmlx.a -framework OpenGL -framework Appkit

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

.PHONY: re all clean fclean
