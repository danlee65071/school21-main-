# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/05 17:08:18 by hcharlsi          #+#    #+#              #
#    Updated: 2021/05/05 17:08:21 by hcharlsi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = add_width.c flag_digit.c flag_dot.c flag_minus.c flags_init.c flags_width.c \
		ft_printf.c is_type.c itoa_u.c parse_flags.c parse_input.c \
		proc_char.c proc_hex.c proc_int.c proc_percent.c proc_pointer.c \
		proc_string.c proc_uint.c processor.c put_str_with_precision.c

OBJS = $(patsubst %.c, %.o, $(SRCS))

HEADER = ft_printf.h

LIBFT = libft

LIBFT_A = libft/libft.a

LIBFT_HEADER = libft/libft.h

FLAGS = -Wall -Werror -Wextra

RM = rm -f

%.o: %.c
	gcc $(FLAGS) -c $< -I $(LIBFT_HEADER) -I $(HEADER) -o $@

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp $(LIBFT_A) $(NAME)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
