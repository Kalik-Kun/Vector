
cmake_minimum_required(VERSION 3.16)

project(Vector)

set(PROJECT Vector)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_EXE main.cpp)

set(SOURCE_LIB Vector.cpp Vector.h unit_test.cpp unit_test.h)

add_library(Vector_lib STATIC ${SOURCE_LIB})

add_executable(${PROJECT} ${SOURCE_EXE})

target_link_libraries(${PROJECT} Vector_lib)