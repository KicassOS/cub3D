# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 17:06:58 by pszleper          #+#    #+#              #
#    Updated: 2023/04/03 23:28:00 by pszleper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = cub3D

SRC =		src/error_handler/error_handler.c		\
			src/error_handler/error_handler_utils.c	\
			src/garbage_ctr/garbage_collector.c		\
			src/get_line/get_next_line.c			\
			src/get_line/get_next_line_utils.c		\
			src/getters/getters_direction.c			\
			src/getters/getters_rgb_path.c			\
			src/parsing/info_loading.c				\
			src/lib/ft_atoi.c						\
			src/lib/ft_isdigit.c					\
			src/lib/ft_putchar_fd.c					\
			src/lib/ft_putnbr_fd.c					\
			src/lib/ft_putstr_fd.c					\
			src/lib/ft_split.c						\
			src/lib/ft_strchr.c						\
			src/lib/ft_strdup.c						\
			src/lib/ft_striteri.c					\
			src/lib/ft_strjoin.c					\
			src/lib/ft_strlen.c						\
			src/lib/ft_strncmp.c					\
			src/lib/ft_strnstr.c					\
			src/lib/ft_strrchr.c					\
			src/lib/ft_split_str.c					\
			src/lst_management/add_lst.c			\
			src/lst_management/create_lst.c			\
			src/lst_management/init_lst.c			\
			src/lst_management/print_lst.c			\
			src/parsing/fill_params.c				\
			src/parsing/fill_parsed_params.c		\
			src/parsing/get_file.c					\
			src/parsing/get_file_extension.c		\
			src/parsing/get_file_utils.c			\
			src/parsing/get_file_utils_2.c			\
			src/parsing/get_map.c					\
			src/parsing/get_maps_utilspp.c			\
			src/parsing/get_map_utils.c				\
			src/parsing/parse_node_params.c			\
			src/parsing/parse_requirement_params.c	\
			src/parsing/parse_rgb.c					\
			src/parsing/parsing_utils.c				\
			src/raycasting/raycast.c				\
			src/rendering/mlx_utils.c				\
			src/rendering/render.c					\
			src/player_movements.c					\
			src/player_rotation.c					\
			src/input_handling.c					\
			src/init_player_view.c					\
			src/main.c

OBJECTS = $(SRC:.c=.o)

HEADER = includes/define.h

all: libmlx_Linux.a $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c -I/usr/include -Iincludes -Imlx_linux -lm $< -o $@

libmlx_Linux.a:
	make -C mlx_linux
	cp mlx_linux/libmlx_Linux.a .

clean:
	find . -name "*.o" -type f -delete
	find . -name "*.h.gch" -type f -delete

fclean: clean
	rm -f libmlx_Linux.a
	rm -f $(NAME)

re: fclean all
