cmake_minimum_required(VERSION 3.17)
project(conveyer_belt)

set(CMAKE_CXX_STANDARD 17)

add_executable(conveyer_belt main.cpp conveyor_belt.cpp conveyor_belt.h shuffling.cpp shuffling.h worker.cpp worker.h simulation.cpp simulation.h)