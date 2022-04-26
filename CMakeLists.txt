cmake_minimum_required(VERSION 3.0.0)
project(library)

file(GLOB SOURCES include/*.hpp src/*.cpp)

add_executable(library ${SOURCES})