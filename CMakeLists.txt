cmake_minimum_required(VERSION 3.10)

project(PPM)

find_package(fmt CONFIG REQUIRED)

add_executable(PPM main.cpp)

target_link_libraries(PPM PRIVATE fmt::fmt)