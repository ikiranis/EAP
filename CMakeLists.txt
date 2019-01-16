cmake_minimum_required(VERSION 3.13)
project(eap C)

set(CMAKE_C_STANDARD 99)

add_executable(eap main.c)
add_executable(test_pointers test_pointers.c)