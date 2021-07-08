# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/05 17:05:14 by hcharlsi          #+#    #+#              #
#    Updated: 2021/07/05 17:49:16 by hcharlsi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = philo.c
DIR_SRCS = srcs
PATH_SRCS = $(addprefix $(DIR_SRCS)/, $(SRCS))

HEADERS = philo.h
DIR_HEADERS = includes
PATH_HEADERS = $(addprefix $(DIR_HEADERS)/, $(HEADERS))

OBJS = $(patsubst %.c, %.o, $(SRCS))
DIR_OBJS = objs
PATH_OBJS = $(addprefix $(DIR_OBJS)/, $(OBJS))

CC = gcc

FLAGS = -Wall -Werror -Wextra -lpthread -g

RM = rm -rf

GREEN = \033[0;32m
RESET = \033[0m

all: $(NAME)

$(NAME): $(PATH_OBJS)
	@$(CC) $(FLAGS) -I $(DIR_HEADERS) $< -o $@
	@#echo "$(GREEN) . $(RESET)"
	@echo "$(GREEN) philo - [ok] $(RESET)"
	@echo "\n\
		   ░░░░░▄▄▄▄▀▀▀▀▀▀▀▀▄▄▄▄▄▄░░░░░░░░\n\
           ░░░░░█░░░░▒▒▒▒▒▒▒▒▒▒▒▒░░▀▀▄░░░░\n\
           ░░░░█░░░▒▒▒▒▒▒░░░░░░░░▒▒▒░░█░░░\n\
           ░░░█░░░░░░▄██▀▄▄░░░░░▄▄▄░░░░█░░\n\
           ░▄▀▒▄▄▄▒░█▀▀▀▀▄▄█░░░██▄▄█░░░░█░\n\
           █░▒█▒▄░▀▄▄▄▀░░░░░░░░█░░░▒▒▒▒▒░█\n\
           █░▒█░█▀▄▄░░░░░█▀░░░░▀▄░░▄▀▀▀▄▒█\n\
           ░█░▀▄░█▄░█▀▄▄░▀░▀▀░▄▄▀░░░░█░░█░\n\
           ░░█░░░▀▄▀█▄▄░█▀▀▀▄▄▄▄▀▀█▀██░█░░\n\
           ░░░█░░░░██░░▀█▄▄▄█▄▄█▄████░█░░░\n\
           ░░░░█░░░░▀▀▄░█░░░█░█▀██████░█░░\n\
           ░░░░░▀▄░░░░░▀▀▄▄▄█▄█▄█▄█▄▀░░█░░\n\
           ░░░░░░░▀▄▄░▒▒▒▒░░░░░░░░░░▒░░░█░\n\
           ░░░░░░░░░░▀▀▄▄░▒▒▒▒▒▒▒▒▒▒░░░░█░\n\
           ░░░░░░░░░░░░░░▀▄▄▄▄▄░░░░░░░░█░░"

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c $(PATH_HEADERS)
	@mkdir -p $(DIR_OBJS)
	@$(CC) $(FLAGS) -I $(DIR_HEADERS) -c $< -o $@
	@#echo "$(GREEN) . $(RESET)"
	@echo "$(GREEN) objects were created $(RESET)"

clean:
	@$(RM) $(DIR_OBJS)
	@echo "$(GREEN) objects were deleted $(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(GREEN) objects and $(NAME) were deleted  $(RESET)"

re: fclean all

.PHONY: all clean fclean
