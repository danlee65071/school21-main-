cmake_minimum_required(VERSION 3.19)
project(ft_printf C)

set(CMAKE_C_STANDARD 99)

add_subdirectory(./libft)
add_executable(ft_printf main.c)

target_link_directories(ft_printf libft)