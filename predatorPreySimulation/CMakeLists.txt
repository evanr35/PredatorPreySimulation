cmake_minimum_required(VERSION 3.10)
project(predatorPreySimulation)

set(CMAKE_CXX_STANDARD 11)

add_executable(predatorPreySimulation main.cpp organism.cpp organism.h grid.cpp grid.h ant.cpp ant.h doodleBug.cpp doodleBug.h simulator.h simulator.cpp RandomGenerator.h RandomGenerator.cpp)