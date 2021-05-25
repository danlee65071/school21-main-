cmake_minimum_required(VERSION 3.19)
project(miniRT C)

set(CMAKE_C_STANDARD 99)

find_library(mlxlib libmlx.dylib)

add_executable(miniRT main.c
        figure/new_sphere.c
        scene/new_camera.c
        scene/new_scene.c
        utils/error_call.c
        vector_operations/new_vector.c
        vector_operations/vector_dot_product.c
        vector_operations/vector_length.c
        vector_operations/vector_normalize.c
        vector_operations/vector_subtraction.c)

target_link_libraries(miniRT mlxlib)