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

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS_PATH)
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/$(LIBFT) .
	@echo "$(GREEN) libft - [ok] $(RESET)"
	@$(CC) $(FLAGS) -I $(DIR_HEADER) $(LIBFT) $(OBJS_PATH) -o $@
	@echo "$(GREEN) $(NAME) - [ok] $(RESET)"

bonus: $(BONUS_OBJS_PATH)
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/$(LIBFT) .
	@echo "$(GREEN) libft - [ok] $(RESET)"
	@$(CC) $(FLAGS) -I $(DIR_HEADER) $(LIBFT) $(BONUS_OBJS_PATH) -o $(NAME)
	@echo "$(GREEN) bonus - [ok] $(RESET)"

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
	@mkdir -p $(DIR_OBJS)
	@$(CC) $(FLAGS) -I $(DIR_HEADER) -I $(LIBFT_DIR) -c $< -o $@

clean:
	@$(RM) $(DIR_OBJS)
	@make clean -C $(LIBFT_DIR)
	@echo "$(GREEN) clean - [ok] $(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)
	@echo "$(GREEN) fclean - [ok] $(RESET)"

re: all bonus fclean

#TESTS

TESTS = test1 test2

test1: all
	@./$(NAME) infile "ls -l" "wc -l" outfile
	@< infile ls -l | wc -l
	@echo "$(GREEN) test1 - [ok] $(RESET)"

test2: all
	@./$(NAME) infile "grep a1" "wc -w" outfile
	@< infile grep a1 | wc -w
	@echo "$(GREEN) test2 - [ok] $(RESET)"

test3: all
	@./$(NAME) infile "grep a1" "wc -w" outfile1
	@< infile grep a1 | wc -w
	@echo "$(GREEN) test3 - [ok] $(RESET)"

test4: all
	@./$(NAME) infil "grep a1" "wc -w" outfile | true
	@< infil grep a1 | wc -w
	@echo "$(GREEN) test4 - [ok] $(RESET)"

#BONUS_TESTS

BONUS_TESTS = bonus_test1 bonus_test2 bonus_test3 bonus_test5 bonus_test6

bonus_test1: bonus
	@./$(NAME) infile "grep a1" "wc -c" "wc -l" outfile
	@< infile grep a1 | wc -c | wc -l
	@echo "$(GREEN) bonus_test1 - [ok] $(RESET)"

bonus_test2: bonus
	@./$(NAME) here_doc a cat "wc -c" outfile
	@cat << a | wc -c
	@echo "$(GREEN) bonus_test2 - [ok] $(RESET)"

bonus_test3: bonus
	@./$(NAME) here_doc a cat "wc -c" "head -n 1" outfile
	@echo "$(GREEN) bonus_test3 - [ok] $(RESET)"

bonus_test4: bonus
	@./$(NAME) here_doc a cat "wc -c" "head -n 1" outfile1
	@cat << a | wc -c | head -n 1
	@echo "$(GREEN) bonus_test4 - [ok] $(RESET)"

bonus_test5: bonus
	@./$(NAME) infil "grep a1" "wc -c" "wc -l" outfile | true
	@< infil grep a1 | wc - c | wc -l
	@echo "$(GREEN) bonus_test5 - [ok] $(RESET)"

bonus_test6: bonus
	@./$(NAME) infile "ls -la" "grep 1" "head -n 5" "wc -l" outfile
	@< infile ls -la | grep 1 | head -n 5 | wc -l
	@echo "$(GREEN) bonus_test6 - [ok] $(RESET)"

bonus_tests: $(BONUS_TESTS)

.PHONY: all clean fclean re
