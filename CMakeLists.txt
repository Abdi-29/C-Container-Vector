cmake_minimum_required(VERSION 3.22)
project(C-Container-Vector)

set (CMAKE_C_STANDARD 99)
set (CMAKE_C_STANDARD_REQUIRED ON)

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wpedantic -Werror")

add_subdirectory(vector)