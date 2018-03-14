cmake_minimum_required(VERSION 3.9)
project(bakers)

set(CMAKE_CXX_STANDARD 11)

add_executable(bakers main.cpp baker.cpp baker.h pie.cpp pie.h)