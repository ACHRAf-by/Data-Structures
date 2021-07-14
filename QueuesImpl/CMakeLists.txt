cmake_minimum_required(VERSION 3.17)
project(QueuesImpl C)

set(CMAKE_C_STANDARD 99)

add_executable(QueuesImpl main.c WithLinkedList.c WithLinkedList.h)