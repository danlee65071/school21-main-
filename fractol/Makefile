# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/04 15:12:56 by hcharlsi          #+#    #+#              #
#    Updated: 2021/06/04 15:12:59 by hcharlsi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = fractol.c my_mlx_put_pixel.c fractol_Julia.c sqrt_complex.c abs_complex.c \
		complex_init.c complex_sum.c init_radius.c create_trgb.c x_close.c \
		esc_close.c mouse_zoom.c

DIR_SRCS = ./srcs/

SRCS_PATH = $(addprefix $(DIR_SRCS), $(SRCS))

DIR_INCLUDES = ./includes/

OBJS = $(patsubst %.c, %.o, $(SRCS_PATH))

LIBMLX = libmlx.a

MLX = -framework OpenGL -framework Appkit libmlx.a

FLAGS = -Wall -Werror -Wextra -g

RM = rm -rf

%.o: %.c
	gcc $(FLAGS) -I $(DIR_INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./minilibx_opengl_20191021
	cp ./minilibx_opengl_20191021/libmlx.a .
	gcc $(FLAGS) -I $(DIR_INCLUDES) $(MLX) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBMLX)
	make clean -C ./minilibx_opengl_20191021

re: clean fclean

.PHONY: all clean fclean re


