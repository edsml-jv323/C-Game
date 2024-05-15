cmake_minimum_required(VERSION 3.27)
project(clean)

set(CMAKE_CXX_STANDARD 17)

add_executable(final main.cpp)

add_executable(creature creature.cpp)

add_executable(main_ex HandlingErrors.cpp RoarTraining.cpp MentalTraining.cpp PhysicalTraining.cpp Training.cpp Monster.cpp Child.cpp Creature.cpp main.cpp)