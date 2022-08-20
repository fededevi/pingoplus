cmake_minimum_required(VERSION 3.5)

project(pingoplus LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file( GLOB_RECURSE SCENE_SRC scene/*.h scene/*.cpp )
file( GLOB_RECURSE MATH_SRC math/*.h math/*.cpp )
file( GLOB_RECURSE GEOMETRY_SRC geometry/*.h geometry/*.cpp )

add_executable(pingoplus main.cpp ${SCENE_SRC} ${MATH_SRC} ${GEOMETRY_SRC})
target_include_directories( pingoplus PUBLIC ./ )
#target_link_libraries(pingoplus PUBLIC geometry math scene)

install(TARGETS pingoplus LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
