# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/11 15:05:14 by hcharlsi          #+#    #+#              #
#    Updated: 2021/07/16 13:58:09 by hcharlsi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

SRCS = philo_bonus.c sem_init.c philo_parser_bonus.c philo_init_bonus.c\
        end_main_bonus.c philo_processes.c utils_bonus.c
DIR_SRCS = srcs
PATH_SRCS = $(addprefix $(DIR_SRCS)/, $(SRCS))

DIR_HEADERS = includes
HEADERS = philo_bonus.h
PATH_HEADERS = $(addprefix $(DIR_HEADERS)/, $(HEADERS))

OBJS = $(patsubst %.c, %.o, $(SRCS))
DIR_OBJS = objs
PATH_OBJS = $(addprefix $(DIR_OBJS)/, $(OBJS))

CC = gcc

FLAGS = -Wall -Werror -Wextra -g

RM = rm -rf

GREEN = \033[0;32m
RESET = \033[0m

all: $(NAME)

$(NAME): $(PATH_OBJS) $(PATH_HEADERS)
	@echo "\n\
		██████╗░██╗░░██╗██╗██╗░░░░░░█████╗░░██████╗░█████╗░██████╗░██╗░░██╗███████╗██████╗░░██████╗\n\
		██╔══██╗██║░░██║██║██║░░░░░██╔══██╗██╔════╝██╔══██╗██╔══██╗██║░░██║██╔════╝██╔══██╗██╔════╝\n\
		██████╔╝███████║██║██║░░░░░██║░░██║╚█████╗░██║░░██║██████╔╝███████║█████╗░░██████╔╝╚█████╗░\n\
		██╔═══╝░██╔══██║██║██║░░░░░██║░░██║░╚═══██╗██║░░██║██╔═══╝░██╔══██║██╔══╝░░██╔══██╗░╚═══██╗\n\
		██║░░░░░██║░░██║██║███████╗╚█████╔╝██████╔╝╚█████╔╝██║░░░░░██║░░██║███████╗██║░░██║██████╔╝\n\
		╚═╝░░░░░╚═╝░░╚═╝╚═╝╚══════╝░╚════╝░╚═════╝░░╚════╝░╚═╝░░░░░╚═╝░░╚═╝╚══════╝╚═╝░░╚═╝╚═════╝░"
	@echo "$(GREEN) objects were created $(RESET)"
	@$(CC) -lpthread $(FLAGS) -I $(DIR_HEADERS) $(PATH_OBJS) -o $@
	@echo "$(GREEN) philo - [ok] $(RESET)"
	@echo "\n\
		   ░░░░░▄▄▄▄▀▀▀▀▀▀▀▀▄▄▄▄▄▄░░░░░░░\n\
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
           ░░░░░░░░░░░░░░▀▄▄▄▄▄░░░░░░░░█░░\n\
           ░░░░░░░░░░░░░░░░░░░░▄▄▄▄▄▄▄▄░░░"

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
	@mkdir -p $(DIR_OBJS)
	@$(CC) $(FLAGS) -I $(DIR_HEADERS) -c $< -o $@

clean:
	@$(RM) $(DIR_OBJS)
	@echo "$(GREEN) objects were deleted $(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(GREEN) objects and $(NAME) were deleted $(RESET)"

re: fclean all

.PHONY: all clean fclean
