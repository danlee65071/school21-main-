cmake_minimum_required(VERSION 3.19)
project(push_swap_lists_ C)

set(CMAKE_C_STANDARD 99)

add_executable(push_swap_lists_ push_swap.c
        ft_lstadd_back.c
        ft_lstnew.c
        ft_parse.c
        ft_atoi.c
        ft_lstlast.c
        ft_error.c
        ft_strlen.c
        ft_is_el_in_list.c
        ft_parse_str.c
        ft_split.c
        ft_sa.c
        ft_lstadd_front.c
        ft_sb.c
        ft_ss.c
        ft_pa.c
        ft_pb.c
        ft_ra.c
        ft_rb.c
        ft_rr.c
        ft_rra.c
        ft_rrb.c
        ft_rrr.c
        ft_sort_arr.c
        ft_lstsize.c
        ft_init_arr.c
        ft_set_indexes_in_sort_arr.c
        ft_find_median.c
        ft_sort.c
        ft_find_place_value.c
        ft_to_top_in_stack.c
        ft_transfer_from_a_to_b.c
        ft_is_in_place.c
        ft_transfer_from_b_to_a.c)