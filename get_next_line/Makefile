# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcassey <fcassey@student.21-school>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/01 21:08:11 by fcassey           #+#    #+##   Updated: 2021/02/03 18:07:00 by aidasajdaseva    ###   ########lyon.fr   #######.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

SRC = get_next_line.c get_next_line_utils.c

SRC_OBJ = $(SRC:.c=.o)

GCC = gcc -Wall -Wextra -Werror -c

all: $(NAME)

.c.o.:
	$(GCC) -I./ $< -o $(<:.c=.o)

$(NAME): $(SRC_OBJ)
	ar rc $(NAME) $(SRC_OBJ)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
 
.PHONY: re all clean fclean get_next_line.a