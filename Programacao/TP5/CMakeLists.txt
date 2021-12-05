cmake_minimum_required(VERSION 3.20)
project(TP5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer")

add_executable(TP5 main.cpp)
add_executable(hello hello.cpp)
add_executable(minMaxSum minMaxSum.cpp)
add_executable(median median.cpp)

