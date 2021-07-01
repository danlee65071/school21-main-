# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/22 00:09:26 by hcharlsi          #+#    #+#              #
#    Updated: 2021/06/22 00:09:29 by hcharlsi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

DIR_SRCS = srcs
SRCS = pipex.c
BONUS_SRCS = pipex_bonus.c cmd_path_bonus.c utils.c here_doc.c get_next_line.c

DIR_HEADER = includes

DIR_OBJS = objs
OBJS = $(patsubst %.c, %.o, $(SRCS))
OBJS_PATH = $(addprefix $(DIR_OBJS)/, $(OBJS))
BONUS_OBJS = $(patsubst %.c, %.o, $(BONUS_SRCS))
BONUS_OBJS_PATH = $(addprefix $(DIR_OBJS)/, $(BONUS_OBJS))

LIBFT = libft.a
LIBFT_DIR = libft

CC = gcc

FLAGS = -Wall -Werror -Wextra -g

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS_PATH)
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/$(LIBFT) .
	@$(CC) $(FLAGS) -I $(DIR_HEADER) $(LIBFT) $(OBJS_PATH) -o $@

bonus: $(BONUS_OBJS_PATH)
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/$(LIBFT) .
	@$(CC) $(FLAGS) -I $(DIR_HEADER) $(LIBFT) $(BONUS_OBJS_PATH) -o $(NAME)

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
	@mkdir -p $(DIR_OBJS)
	@$(CC) $(FLAGS) -I $(DIR_HEADER) -I $(LIBFT_DIR) -c $< -o $@

clean:
	@$(RM) $(DIR_OBJS)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)

re: all bonus fclean

BONUS_TESTS = bonus_test1 bonus_test2 bonus_test3 bonus_test5 bonus_test6

bonus_test1: bonus
	@./$(NAME) infile "grep a1" "wc -c" "wc -l" outfile

bonus_test2: bonus
	@./$(NAME) here_doc a cat "wc -c" outfile

bonus_test3: bonus
	@./$(NAME) here_doc a cat "wc -c" "head -n 1" outfile

bonus_test4: bonus
	@./$(NAME) here_doc a cat "wc -c" "head -n 1" outfile1

bonus_test5: bonus
	@./$(NAME) infil "grep a1" "wc -c" "wc -l" outfile

bonus_test6: bonus
	@./$(NAME) infile "ls -la" "grep 1" "head -n 5" "wc -l" outfile

bonus_tests: bonus_test1 bonus_test2

.PHONY: all clean fclean re
