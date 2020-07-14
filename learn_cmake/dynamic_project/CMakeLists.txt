cmake_minimum_required(VERSION 3.10) # 最低版本要求

set(project_name Exp2)
project(${project_name})

set(CMAKE_CXX_COMPILER "c++")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS -g -Wall)
string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
message(STATUS "CMAKE_CXX_FLAGS: " "${CMAKE_CXX_FLAGS}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin/)

message(STATUS "source dir: " ${PROJECT_SOURCE_DIR})
message(STATUS "binary dir: " ${PROJECT_BINARY_DIR})
message(STATUS "output dir: " "${PROJECT_BINARY_DIR}/${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

include_directories(.)
aux_source_directory(. SOURCE_DIR)

set(static_lib_source_file archive/calculator.cc)

add_library(calculator_shared SHARED ${static_lib_source_file})

add_executable(${project_name} ${SOURCE_DIR})

target_link_libraries(${project_name} calculator_shared)
