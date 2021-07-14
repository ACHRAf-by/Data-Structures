cmake_minimum_required(VERSION 3.17)
project(grammaire C)

set(CMAKE_C_STANDARD 99)

add_executable(grammaire main.c grammaire.c grammaire.h)