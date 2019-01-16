cmake_minimum_required(VERSION 3.13)
project(eap C)

set(CMAKE_C_STANDARD 99)

add_executable(eap main.c)
add_executable(test_pointers test_pointers.c)
add_executable(ascii_chars ascii_chars.c)
add_executable(print_ascii_table print_ascii_table.c)
add_executable(constExample constExample.c)
add_executable(findIntegersWithSum8 findIntegersWithSum8.c)