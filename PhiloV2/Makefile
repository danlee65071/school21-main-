# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/11 15:05:14 by hcharlsi          #+#    #+#              #
#    Updated: 2021/07/11 15:05:20 by hcharlsi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = philo.c philo_parser.c utils.c philo_init.c forks_init.c philo_threads.c\
		waiter.c end_main.c
DIR_SRCS = srcs
PATH_SRCS = $(addprefix $(DIR_SRCS)/, $(SRCS))

HEADERS = philo.h
DIR_HEADERS = includes
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

$(NAME): $(PATH_OBJS)
	@echo "\n\
		██████╗░██╗░░██╗██╗██╗░░░░░░█████╗░░██████╗░█████╗░██████╗░██╗░░██╗███████╗██████╗░░██████╗\n\
		██╔══██╗██║░░██║██║██║░░░░░██╔══██╗██╔════╝██╔══██╗██╔══██╗██║░░██║██╔════╝██╔══██╗██╔════╝\n\
		██████╔╝███████║██║██║░░░░░██║░░██║╚█████╗░██║░░██║██████╔╝███████║█████╗░░██████╔╝╚█████╗░\n\
		██╔═══╝░██╔══██║██║██║░░░░░██║░░██║░╚═══██╗██║░░██║██╔═══╝░██╔══██║██╔══╝░░██╔══██╗░╚═══██╗\n\
		██║░░░░░██║░░██║██║███████╗╚█████╔╝██████╔╝╚█████╔╝██║░░░░░██║░░██║███████╗██║░░██║██████╔╝\n\
		╚═╝░░░░░╚═╝░░╚═╝╚═╝╚══════╝░╚════╝░╚═════╝░░╚════╝░╚═╝░░░░░╚═╝░░╚═╝╚══════╝╚═╝░░╚═╝╚═════╝░"
	@echo "$(GREEN) objects were created $(RESET)"
	@$(CC) -lpthread $(FLAGS) -I $(DIR_HEADERS) $(PATH_OBJS) -o $@
	@#echo "$(GREEN) . $(RESET)"
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

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c $(PATH_HEADERS)
	@mkdir -p $(DIR_OBJS)
	@$(CC) $(FLAGS) -I $(DIR_HEADERS) -c $< -o $@
	@#echo "$(GREEN) . $(RESET)"

clean:
	@$(RM) $(DIR_OBJS)
	@echo "$(GREEN) objects were deleted $(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(GREEN) objects and $(NAME) were deleted  $(RESET)"

re: fclean all

.PHONY: all clean fclean
