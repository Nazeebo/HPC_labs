cmake_minimum_required(VERSION 3.8)
project(myVector)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c vector.c vector.h)
add_executable(myVector ${SOURCE_FILES})