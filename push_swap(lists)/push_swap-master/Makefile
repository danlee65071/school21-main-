# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/13 18:35:13 by sscottie          #+#    #+#              #
#    Updated: 2020/02/12 16:53:09 by sscottie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RED_B = \033[1;4;31m
BLUE = \033[1;4;34m
RESET = \033[0m

P_S 		= push_swap
CH			= checker
PR			= preparator
CFLAGS		= -Wall -Wextra -Werror
INC			= -I include
FT_PF 		= ./lib/ft_printf/
SRC_DIR		= ./src/
OBJ_DIR 	= obj/
PF_A		= ./lib/ft_printf/libftprintf.a
HEADER		= push_swap.h
PF_H		= ft_printf.h
PF_INC		= -I ./lib/ft_printf/include

SRC_P_S		= push_swap.c \
				validate.c \
				converter.c \
				production.c \
				algorithm.c \
				swap.c \
				swap_two.c \
				rotate.c \
				reverse_rotate.c \
				push.c \
				push_two.c \
				double_stack.c \
				helper.c \
				linked_lists.c \
				linked_lists_two.c \
				quick_sort.c

SRC_CH		= checker.c \
				validate.c \
				converter.c \
				production.c \
				algorithm.c \
				swap.c \
				swap_two.c \
				rotate.c \
				reverse_rotate.c \
				push.c \
				push_two.c \
				double_stack.c \
				helper.c \
				linked_lists.c \
				linked_lists_two.c \
				quick_sort.c \
				reader.c

SRC_PR		= preparator.c \
				validate.c \
				converter.c \
				production.c \
				algorithm.c \
				swap.c \
				swap_two.c \
				rotate.c \
				reverse_rotate.c \
				push.c \
				push_two.c \
				double_stack.c \
				helper.c \
				linked_lists.c \
				linked_lists_two.c \
				quick_sort.c


SRC_C_P_S	= $(addprefix $(SRC_DIR), $(SRC_P_S))
SRC_C_CH	= $(addprefix $(SRC_DIR), $(SRC_CH))
SRC_C_PR	= $(addprefix $(SRC_DIR), $(SRC_PR))

all: pf $(P_S) $(CH) $(PR)

$(P_S):: pf
	gcc $(CFLAGS) $(SRC_C_P_S) -o $(P_S) $(INC) $(PF_INC) $(PF_A)
$(CH):: pf
	gcc $(CFLAGS) $(SRC_C_CH) -o $(CH) $(INC) $(PF_INC) $(PF_A)

$(PR):: pf 
	gcc $(CFLAGS) $(SRC_C_PR) -o $(PR) $(INC) $(PF_INC) $(PF_A) 

pf: 
	make -C ./lib/ft_printf/

clean:
	@make -C ./lib/ft_printf clean

fclean: clean
	@rm -rf $(P_S)
	@rm -rf $(CH)
	@make -C ./lib/ft_printf fclean
	@rm -rf $(PR)

re: fclean all