cmake_minimum_required(VERSION 3.0)
include_directories( "/usr/include/eigen3" )
project(eigenmatrix)

add_executable(eigenmatrix main.cpp)

install(TARGETS eigenmatrix RUNTIME DESTINATION bin)
