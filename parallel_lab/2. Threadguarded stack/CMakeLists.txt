cmake_minimum_required(VERSION 3.10)
project(2__Threadguarded_stack)

set(CMAKE_CXX_STANDARD 11)

add_executable(2__Threadguarded_stack main.cpp threadsave_stack.h defines.h)