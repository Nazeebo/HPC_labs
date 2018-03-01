cmake_minimum_required(VERSION 3.9)
project(2__inheritance)

set(CMAKE_CXX_STANDARD 11)

add_executable(2__inheritance main.cpp characters/knight.cpp characters/knight.h characters/goblin.cpp characters/goblin.h characters/mage.cpp characters/mage.h characters/hero.cpp characters/hero.h game.cpp game.h helping_funcs.cpp helping_funcs.h action.cpp action.h)