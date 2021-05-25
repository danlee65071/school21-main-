# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/24 13:33:45 by hcharlsi          #+#    #+#              #
#    Updated: 2021/05/24 13:33:48 by hcharlsi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

SRCS = main.c intersection/sphere_intersection.c raytracing/get_view_plane.c raytracing/raytracing.c \
		scene/new_camera.c scene/new_scene.c utils/error_call.c vector_operations/new_vector.c \
		vector_operations/vector_dot_product.c vector_operations/vector_length.c vector_operations/vector_normalize.c \
		vector_operations/vector_subtraction.c figure/new_sphere.c

HEADERS = includes/camera.h includes/minirt.h includes/scene.h includes/sphere.h includes/sphere_intersection.h \
		includes/utils.h includes/vector.h includes/view_plane.h

OBJS = $(patsubst %.c, %.o, $(SRCS))

LIBMLX_PATH = mlx

LIBMLX = mlx/libmlx.dylib

FLAGS = -Wall -Werror -Wextra -g

RM = rm -rf

MLX = -Lmlx -lmlx -framework OpenGL -framework Appkit

CC = gcc

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	make -C $(LIBMLX_PATH)
	cp $(LIBMLX) $(NAME)
	$(CC) $(FLAGS) $(MLX) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)
	make -C $(LIBMLX_PATH) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBMLX_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
