# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcassey <fcassey@student.21-school>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/01 21:08:11 by fcassey           #+#    #+#              #
#    Updated: 2020/11/08 18:37:51 by fcassey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_memset.c\
	ft_bzero.c\
	ft_memcpy.c\
	ft_memccpy.c\
	ft_memmove.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_strlen.c\
	ft_strlcpy.c\
	ft_strlcat.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strnstr.c\
	ft_strncmp.c\
	ft_atoi.c\
	ft_isalpha.c\
	ft_isdigit.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_calloc.c\
	ft_strdup.c\
	ft_substr.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_split.c\
	ft_itoa.c\
	ft_strmapi.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_spacealloc.c\
	ft_intstrchr.c\

SRC_OBJ = $(SRC:.c=.o)

BONUS = ft_lstnew.c\
	ft_lstadd_front.c\
	ft_lstadd_back.c\
	ft_lstsize.c\
	ft_lstlast.c\
	ft_lstdelone.c\
	ft_lstclear.c\
	ft_lstiter.c\
	ft_lstmap.c\

BONUS_OBJ = $(BONUS:.c=.o)

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

bonus: $(SRC_OBJ) $(BONUS_OBJ)
	ar rc $(NAME) $(BONUS_OBJ)
 
.PHONY: re all clean fclean libft.a bonus