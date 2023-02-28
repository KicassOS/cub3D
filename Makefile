# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 17:06:58 by pszleper          #+#    #+#              #
#    Updated: 2023/02/28 17:36:26 by pszleper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = cub3D

SRC = main.c

OBJECTS = $(addprefix objects/, main.o)

HEADER = cub3D.h

all: libmlx_Linux.a $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) -Lminilibx_opengl -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -framework OpenGL -framework AppKit -o $(NAME)

objects/%.o: src/%.c
	mkdir -p objects
	$(CC) $(FLAGS) $(HEADER) -I/usr/include -Imlx_linux $< -c
	mv *.o objects/

libmlx_Linux.a:
	make -C mlx_linux
	cp mlx_linux/libmlx_Linux.a .

clean:
	rm -f objects/*.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
