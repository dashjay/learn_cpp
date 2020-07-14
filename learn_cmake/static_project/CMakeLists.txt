cmake_minimum_required(VERSION 3.10) # 最低版本要求

project(SingleFile) # 项目名称

set(CMAKE_CXX_COMPILER "c++")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS -g -Wall)
message(STATUS "CMAKE_CXX_FLAGS: " "${CMAKE_CXX_FLAGS}")
string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
message(STATUS "CMAKE_CXX_FLAGS: " "${CMAKE_CXX_FLAGS}")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin/)

message(STATUS "source dir: " ${PROJECT_SOURCE_DIR})
message(STATUS "binary dir: " ${PROJECT_BINARY_DIR})
message(STATUS "output dir: " ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

include_directories(./)
aux_source_directory(./ SOURCE_DIR)

link_directories(archive/)

add_executable(Exp2 ${SOURCE_DIR})

target_link_libraries(Exp2 libcalculator.a)
