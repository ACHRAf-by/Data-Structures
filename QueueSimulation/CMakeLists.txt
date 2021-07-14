cmake_minimum_required(VERSION 3.17)
project(QueueSimulation C)

set(CMAKE_C_STANDARD 99)

add_executable(QueueSimulation main.c Simulations.c Simulations.h)