cmake_minimum_required(VERSION 3.18.0)

project(vector)

# ---[ Options ]----------------------------
set(LIB_NAME vector)

# ---[ Create library ]---------------------
add_library(${LIB_NAME} STATIC
        srcs/vector.c
        )

# ---[ Include directories ]----------------
target_include_directories(${LIB_NAME} PUBLIC includes)
