# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/11 21:16:31 by hcharlsi          #+#    #+#              #
#    Updated: 2021/06/11 21:16:33 by hcharlsi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = fractol.c utils.c fractol_Julia.c complex_utils.c mouse_zoom.c keyboard.c \
		fractol_Mandelbrot.c parse.c ft_strcmp.c fractol_BurningShip.c
SRCS_DIR = srcs

OBJS = $(patsubst %.c, %.o, $(SRCS))
OBJS_DIR = objs
OBJS_PATH = $(addprefix $(OBJS_DIR)/, $(OBJS))

HEADER_DIR = ./includes/

LIBFT = libft.a
LIBFT_DIR = ./libft
LIBFT_HEADER = libft.h
LIBFT_HEADER_PATH = $(addprefix $(LIBFT_DIR)/, $(LIBFT_HEADER))

LIBMLX = libmlx.dylib
MLX_DIR = ./mlx
MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit

FLAGS = -Werror -Wextra -Wall -g

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS_PATH)
	make -C $(MLX_DIR)
	cp $(MLX_DIR)/$(LIBMLX) .
	make -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/$(LIBFT) .
	gcc $(FLAGS) -I $(HEADER_DIR) $(MLX) $(LIBFT) $^ -o $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	mkdir $(OBJS_DIR) 2> /dev/null || true
	gcc $(FLAGS) -Imlx -I $(HEADER_DIR) -I $(LIBFT_DIR) -c $< -o $@

clean:
	$(RM) $(OBJS_PATH)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
	$(RM) $(OBJS_DIR) 2> /dev/null || true

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBMLX)
	$(RM) $(LIBFT)
	make fclean -C $(LIBFT_DIR)

re: all clean fclean

.PHONY: all clean fclean re
