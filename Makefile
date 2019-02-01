# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/07 11:13:09 by prastoin          #+#    #+#              #
#    Updated: 2019/01/24 12:58:32 by ochaar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC = main.c ft_verif.c ft_error.c

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror -Ofast

LIB = libft/libft.a

LIBX = -lmlx -framework OpenGL -framework AppKit

INC = -I./libft/ -I/usr/local/include

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
		gcc $(FLAG) $(LIB) $(INC) $(OBJ) $(LIBX) -o $(NAME)

$(LIB):
		make -C libft/ fclean
			make -C ./libft/

%.o: %.c frac.h
		gcc $(FLAG) $(INC) -o $@ -c $<

clean:
		make -C libft/ clean
			rm -rf $(OBJ)

fclean: clean
		make -C libft/ fclean
			rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all
