cmake_minimum_required(VERSION 3.28)
project(pr11_g C)

set(CMAKE_C_STANDARD 11)

add_executable(pr11_g main.c
        student_fields_macroses.h
        student.h
        node_list_for_students.h
        node_list_for_students.c
        binary_tree.h
        binary_tree.c)
