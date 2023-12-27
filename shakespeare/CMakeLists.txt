cmake_minimum_required(VERSION 3.22.1)

set(CMAKE_CXX_STANDARD 23)

project(shakespeare VERSION 2023.0)

file(GLOB SOURCES "src/*.cpp")

include_directories("include")

add_executable(shakespeare ${SOURCES})
