cmake_minimum_required(VERSION 3.9)
project(lab_8)

set(CMAKE_CXX_STANDARD 11)

add_executable(lab_8 main.cpp characters/knight.cpp characters/knight.h characters/goblin.cpp characters/goblin.h characters/mage.cpp characters/mage.h player.cpp player.h game.cpp game.h helping_funcs.cpp helping_funcs.h)