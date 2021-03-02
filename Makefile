NAME = test.out

all:	${NAME}

${NAME}:
		make -C ./libft/
		cp ./libft/libft.a .
		make -C ./get_next_line/
		cp ./get_next_line/get_next_line.a .
		gcc *.c -o ${NAME} libft.a get_next_line.a

clean:
		rm -f ./libft/*.o
		rm -f ./get_next_line/*.o

fclean:	clean
		rm -f libft.a
		rm -f get_next_line.a
		rm -f ${NAME}

re:		fclean all

.PHONY: re all clean fclean
