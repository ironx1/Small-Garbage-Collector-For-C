cmake_minimum_required(VERSION 3.25)
project(Garbage_collector C)

set(CMAKE_C_STANDARD 23)

add_executable(Garbage_collector main.c garbage_collector.h garbage_collector.c)
