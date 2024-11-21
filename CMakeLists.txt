cmake_minimum_required(VERSION 3.27)
project(CC C)

set(CMAKE_C_STANDARD 11)

add_executable(CC main.c
        queue.c
        queue.h
        stack.c
        stack.h
        cell.c
        cell.h
        list.c
        list.h
        node.c
        node.h
        tree.c
        tree.h)
