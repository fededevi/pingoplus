cmake_minimum_required(VERSION 3.5)

project(pingoplus LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file( GLOB_RECURSE MATH_SRC math/*.h math/*.cpp )

set( SRC ${MATH_SRC} )

add_executable(pingoplus main.cpp ${SRC})

install(TARGETS pingoplus
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
