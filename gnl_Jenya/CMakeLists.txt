cmake_minimum_required(VERSION 3.19)
project(gnl_Jenya C)

set(CMAKE_C_STANDARD 99)

add_executable(gnl_Jenya main.c
        get_next_line.c
        get_next_line_utils.c)