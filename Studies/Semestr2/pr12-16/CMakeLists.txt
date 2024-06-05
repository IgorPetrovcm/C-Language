cmake_minimum_required(VERSION 3.28)
project(pr12_16_3 C)

set(CMAKE_C_STANDARD 11)

add_executable(pr12_16_3 main.c
        Core/Domain/student.h
        Core/Application/node_list.h
        Services/node_list.c
        Core/Application/universal_pointer.h
        Core/Application/file_context.h
        Services/file_context.c
        Core/Application/logging.h
        Services/logging.c
        tools/tools.h
        tools/tools.c)
