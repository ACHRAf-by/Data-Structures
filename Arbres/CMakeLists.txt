cmake_minimum_required(VERSION 3.17)
project(Arbres C)

set(CMAKE_C_STANDARD 99)

add_executable(Arbres main.c Fonctions.c Fonctions.h QueueForBreadthTraversal.c QueueForBreadthTraversal.h)