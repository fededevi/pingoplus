cmake_minimum_required(VERSION 3.5)

project(pingoplus LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(pingoplus main.cpp)

install(TARGETS pingoplus
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
