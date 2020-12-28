cmake_minimum_required(VERSION 3.14)
project(clrs)

set(CMAKE_CXX_STANDARD 20)

set(src 
    src/main.cpp
    src/insertion_sort.hpp
    src/inversion_counter.hpp
)

add_executable(clrs ${src})

target_link_libraries(clrs PRIVATE
                pthread
                ncurses
                fmt
                )   
