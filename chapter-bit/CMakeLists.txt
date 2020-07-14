cmake_minimum_required(VERSION 3.10) # 最低版本要求

project(SingleFile) # 项目名称

set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS -g -Wall)
message(STATUS "CMAKE_CXX_FLAGS: " "${CMAKE_CXX_FLAGS}")
string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
message(STATUS "CMAKE_CXX_FLAGS: " "${CMAKE_CXX_FLAGS}")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin/)

add_executable(2_q_2.cpp.o 2_q_2.cpp)
add_executable(bit_test.cpp.o bit_test.cpp)
