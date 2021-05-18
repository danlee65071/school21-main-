# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 19:29:58 by hcharlsi          #+#    #+#              #
#    Updated: 2021/05/18 19:29:59 by hcharlsi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = push_swap.c ft_lstadd_back.c ft_lstnew.c ft_parse.c ft_atoi.c ft_lstlast.c ft_error.c ft_strlen.c \
               ft_is_el_in_list.c ft_parse_str.c ft_split.c ft_sa.c ft_lstadd_front.c ft_sb.c ft_ss.c \
               ft_pa.c ft_pb.c ft_ra.c ft_rb.c ft_rr.c ft_rra.c ft_rrb.c ft_rrr.c ft_sort_arr.c ft_lstsize.c \
               ft_init_arr.c ft_set_indexes_in_sort_arr.c ft_find_median.c ft_sort.c ft_find_place_value.c \
               ft_to_top_in_stack.c ft_transfer_from_a_to_b.c ft_is_in_place.c ft_transfer_from_b_to_a.c \
               ft_part_of_the_stack.c ft_lstdel.c ft_top_el_wich_was_in_b.c

OBJS = $(patsubst %.c, %.o, $(SRCS))

HEADER = push_swap.h

FLAGS = -Wall -Werror -Wextra

RM = rm -rf

%.o: %.c
		gcc $(FLAGS) -c $< -I $(HEADER) -o $@

$(NAME): $(OBJS)
		gcc  $(FLAGS) -I $(HEADER) $(OBJS) -o $(NAME)

all: $(NAME)


clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re