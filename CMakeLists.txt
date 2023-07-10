cmake_minimum_required(VERSION 3.25)
project(swap_and_ptrs C)

set(CMAKE_C_STANDARD 23)

add_executable(swap_and_ptrs main.c swap.c make_ptrs_array.c make_ptrs_array.h pointers_merge_sort.c
        pointers_merge_sort.h)