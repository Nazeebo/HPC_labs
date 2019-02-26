cmake_minimum_required(VERSION 3.10)
project(4__Shared_mutex)

set(CMAKE_CXX_STANDARD 11)

add_executable(4__Shared_mutex main.cpp shared_mutex.h defines.h shared_mutex.cpp thread_guard.cpp thread_guard.hpp)